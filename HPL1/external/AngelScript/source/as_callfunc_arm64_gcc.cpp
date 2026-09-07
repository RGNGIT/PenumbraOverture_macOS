/*
   AngelCode Scripting Library
   Copyright (c) 2003-2006 Andreas Jönsson

   This software is provided 'as-is', without any express or implied
   warranty. In no event will the authors be held liable for any
   damages arising from the use of this software.

   Permission is granted to anyone to use this software for any
   purpose, including commercial applications, and to alter it and
   redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you
	  must not claim that you wrote the original software. If you use
	  this software in a product, an acknowledgment in the product
	  documentation would be appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and
	  must not be misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
	  distribution.

   The original version of this library can be located at:
   http://www.angelcode.com/angelscript/

   Andreas Jönsson
   andreas@angelcode.com
*/

/*
 * Implements the AAPCS64 (ARM64 / Apple Silicon) calling convention.
 *
 * This file is a hand-port of the SAME AAPCS64 calling-convention work
 * already done (and battle-tested) for AngelScript 2.19.2 as part of a
 * separate Mac ARM64 porting project, adapted here for THIS older
 * (2006-era, 2.7.1) SDK's specific internal structures - which are broadly
 * similar in shape (asSSystemFunctionInterface, the internalCallConv enum,
 * the overall CallSystemFunction argument-classification approach) but
 * differ in some concrete details:
 *
 *   - asCContext's register fields (stackPointer, objectRegister,
 *     objectType, and the primitive-return-value register) are DIRECT
 *     members of asCContext in this version, not nested inside a `.regs`
 *     sub-struct like 2.19.2's `context->regs.stackPointer` - and the
 *     primitive-return register is named `register1` here, not
 *     `valueRegister`.
 *   - asCScriptEngine::CallFree() takes an extra `asCObjectType*` argument
 *     here (CallFree(objType, obj)), not just CallFree(obj).
 *   - the raw function-pointer union is `asUPtr` here (flatter layout,
 *     `ptr.f.func`), not 2.19.2's `asSFuncPtr` (`ptr.ptr.f.func`) - not
 *     directly relevant to THIS file, since CallSystemFunction operates on
 *     the already-processed asSSystemFunctionInterface, not the raw
 *     pointer type itself.
 *
 * Same known limitation as the 2.19.2 port: stack-spilled arguments (more
 * than 8 integer/pointer args AND more than 8 float/double args
 * simultaneously) are packed as fixed 8-byte slots, matching x86-64 SysV
 * exactly but not AAPCS64's natural-alignment packing for larger structs.
 * Not expected to matter in practice for this engine's registered API
 * (plain scalar/pointer arguments throughout).
 */

#include "as_config.h"

#ifndef AS_MAX_PORTABILITY
#ifdef AS_ARM64_GCC

#include "as_scriptengine.h"
#include "as_texts.h"
#include "as_callfunc.h"
#include "as_context.h"

BEGIN_AS_NAMESPACE

enum argTypes { arm64ENDARG = 0, arm64INTARG = 1, arm64FLOATARG = 2, arm64DOUBLEARG = 3, arm64VARIABLE = 4 };

#define ARM64_MAX_ARGS				 32
#define MAX_CALL_INT_REGISTERS		 8
#define MAX_CALL_SSE_REGISTERS		 8
#define CALLSTACK_MULTIPLIER		 2
#define ARM64_CALLSTACK_SIZE		 ( ARM64_MAX_ARGS + MAX_CALL_SSE_REGISTERS + 3 )

// Performs the actual native call. Takes a pre-classified argument buffer
// (see the layout comment in CallSystemFunction below) and loads it into
// X0-X7 / D0-D7 / the outgoing stack area, exactly as a normal AAPCS64
// caller would, then branches into the target function.
//
// outFloatBits receives the raw 64 bits of D0 after the call (the low 32
// bits are the correct value for a float return; all 64 bits are the
// correct value for a double return).
// outIntHigh receives X1, used for functions that return a value spanning
// two integer registers.
static asQWORD __attribute__ ((__noinline__)) ARM64_CallFunction( const asDWORD *pArgs,
																	const asBYTE *pArgsType,
																	void *func,
																	void *hiddenRetPtr,
																	asQWORD *outFloatBits,
																	asQWORD *outIntHigh )
{
	volatile asQWORD retval  = 0;
	volatile asQWORD retval2 = 0;
	volatile asQWORD fret	  = 0;
	asQWORD stackcnt = 0;
	int i;

	for (i = MAX_CALL_INT_REGISTERS + MAX_CALL_SSE_REGISTERS;
		 pArgsType[i] != arm64ENDARG && ( i < ARM64_MAX_ARGS + MAX_CALL_SSE_REGISTERS + 3);
		 i++) {
		stackcnt++;
	}

	__asm__ __volatile__ (
		// Back up the current stack pointer in x19 (callee-saved register;
		// since it is listed in the clobber list below, the compiler will
		// save/restore its caller's value around this asm block for us,
		// while its value is guaranteed to survive across the blr call
		// because the callee must itself preserve callee-saved registers).
		"mov x19, sp				\n"

		// Reserve space for outgoing stack arguments (if any), rounded up
		// to a 16-byte boundary as AAPCS64 requires. No red zone on
		// AAPCS64 (unlike x86-64 SysV), so no blind extra skip needed.
		"lsl x12, %[cnt], #3		\n"		// x12 = stackcnt * 8 bytes
		"add x12, x12, #15			\n"
		"and x12, x12, #-16		\n"		// round up to multiple of 16
		"sub sp, sp, x12			\n"

		// Copy outgoing stack arguments into the freshly reserved area.
		// See as_callfunc_arm64_gcc.cpp's 2.19.2 counterpart for the full
		// explanation of why the source region is walked from its highest
		// index down to 0 while writing to ascending destination offsets
		// (reproduces the same final ordering a series of x86 pushes
		// would, matching what the x64 reference port relies on).
		"cbz %[cnt], 2f			\n"
		"mov x13, %[cnt]			\n"
		"sub x13, x13, #1			\n"		// x13 = stackcnt - 1 (highest source index)
		"mov x8, #0					\n"		// x8 = destination byte offset, starts at 0
	"1:									\n"
		"add x14, %[args], #128	\n"
		"lsl x15, x13, #3			\n"
		"add x14, x14, x15			\n"
		"ldr x9, [x14]				\n"
		"str x9, [sp, x8]			\n"
		"add x8, x8, #8				\n"
		"subs x13, x13, #1			\n"
		"b.ge 1b					\n"
	"2:									\n"

		// Load integer/pointer arguments into X0-X7 from pArgs[0..7].
		"ldr x0, [%[args], #0]		\n"
		"ldr x1, [%[args], #8]		\n"
		"ldr x2, [%[args], #16]	\n"
		"ldr x3, [%[args], #24]	\n"
		"ldr x4, [%[args], #32]	\n"
		"ldr x5, [%[args], #40]	\n"
		"ldr x6, [%[args], #48]	\n"
		"ldr x7, [%[args], #56]	\n"

		// Load float/double arguments into D0-D7 from pArgs[8..15]. A
		// plain 8-byte load into the D register is correct for both float
		// and double: AAPCS64 only reads the low 32 bits of the V
		// register for a float argument, so loading the full 8 bytes
		// (with garbage/zero in the upper 32 bits for an actual float
		// value) doesn't change what the callee reads.
		"ldr d0, [%[args], #64]	\n"
		"ldr d1, [%[args], #72]	\n"
		"ldr d2, [%[args], #80]	\n"
		"ldr d3, [%[args], #88]	\n"
		"ldr d4, [%[args], #96]	\n"
		"ldr d5, [%[args], #104]	\n"
		"ldr d6, [%[args], #112]	\n"
		"ldr d7, [%[args], #120]	\n"

		// AAPCS64 reserves X8 specifically as the "indirect result
		// location" register for functions that return their value via a
		// hidden pointer - UNLIKE x86-64 SysV, which passes that same
		// hidden pointer as an ordinary FIRST integer argument in RDI.
		// Loading it here (harmless/ignored by the callee if this call
		// isn't actually a return-in-memory call) keeps it fully separate
		// from the real arguments in X0-X7.
		"mov x8, %[retptr]			\n"

		// Call the function.
		"blr %[fn]					\n"

		// Capture return values before restoring the stack pointer.
		"str x0, %[ret]			\n"
		"str x1, %[ret2]			\n"
		"fmov x9, d0				\n"
		"str x9, %[fretout]		\n"

		// Restore stack pointer to the value saved before the call.
		"mov sp, x19				\n"

		: [ret] "=m" (retval), [ret2] "=m" (retval2), [fretout] "=m" (fret)
		: [cnt] "r" (stackcnt), [args] "r" (pArgs), [fn] "r" (func), [retptr] "r" (hiddenRetPtr)
		// NOTE: this clobber list must include EVERY caller-saved AAPCS64
		// general-purpose register, not just the ones this code
		// explicitly uses as scratch space - x16/x17 (IP0/IP1) are
		// especially easy to miss since the dynamic linker's own
		// lazy-symbol-binding stub code uses x16 as its call target
		// register, meaning ANY call that resolves a not-yet-bound symbol
		// (e.g. operator new on its first use) clobbers x16, silently
		// corrupting anything the compiler had stored there if it wasn't
		// told this register may be clobbered.
		: "x0","x1","x2","x3","x4","x5","x6","x7",
		  "x8","x9","x10","x11","x12","x13","x14","x15","x16","x17",
		  "x19","x30",
		  "d0","d1","d2","d3","d4","d5","d6","d7",
		  "cc","memory"
	);

	*outFloatBits = fret;
	*outIntHigh   = retval2;

	return retval;
}

// This function should prepare system functions so that it will be faster to call them.
// NOTE: this is a straight port of as_callfunc_x86.cpp's own PrepareSystemFunction
// (the SDK's ORIGINAL as_callfunc.cpp only ever defined this function inside its
// AS_MAX_PORTABILITY-guarded block - once we stopped forcing AS_MAX_PORTABILITY on
// arm64, that whole block (including this function) stopped compiling, leaving it
// with no definition at all). The THISCALL/CDECL/STDCALL_RETURN_SIMPLE_IN_MEMORY
// guards below are never actually defined on Apple platforms (only WIN32/__linux__
// builds define them), so this behaves identically to the AS_MAX_PORTABILITY
// version in practice here - kept for fidelity with the native-callconv reference
// implementation this was copied from.
int PrepareSystemFunction(asCScriptFunction *func, asSSystemFunctionInterface *internal, asCScriptEngine *)
{
	// References are always returned as primitive data
	if( func->returnType.IsReference() || func->returnType.IsObjectHandle() )
	{
		internal->hostReturnInMemory = false;
		internal->hostReturnSize = 1;
		internal->hostReturnFloat = false;
	}
	// Registered types have special flags that determine how they are returned
	else if( func->returnType.IsObject() )
	{
		asDWORD objType = func->returnType.GetObjectType()->flags;
		if( objType & asOBJ_CLASS )
		{
			if( objType & COMPLEX_MASK )
			{
				internal->hostReturnInMemory = true;
				internal->hostReturnSize = 1;
				internal->hostReturnFloat = false;
			}
			else
			{
				internal->hostReturnFloat = false;
				if( func->returnType.GetSizeInMemoryDWords() > 2 )
				{
					internal->hostReturnInMemory = true;
					internal->hostReturnSize = 1;
				}
				else
				{
					internal->hostReturnInMemory = false;
					internal->hostReturnSize = func->returnType.GetSizeInMemoryDWords();
				}

#ifdef THISCALL_RETURN_SIMPLE_IN_MEMORY
				if( internal->callConv == ICC_THISCALL ||
					internal->callConv == ICC_VIRTUAL_THISCALL )
				{
					internal->hostReturnInMemory = true;
					internal->hostReturnSize = 1;
				}
#endif
#ifdef CDECL_RETURN_SIMPLE_IN_MEMORY
				if( internal->callConv == ICC_CDECL ||
					internal->callConv == ICC_CDECL_OBJLAST ||
					internal->callConv == ICC_CDECL_OBJFIRST )
				{
					internal->hostReturnInMemory = true;
					internal->hostReturnSize = 1;
				}
#endif
#ifdef STDCALL_RETURN_SIMPLE_IN_MEMORY
				if( internal->callConv == ICC_STDCALL )
				{
					internal->hostReturnInMemory = true;
					internal->hostReturnSize = 1;
				}
#endif
			}
		}
		else if( objType == asOBJ_PRIMITIVE )
		{
			internal->hostReturnInMemory = false;
			internal->hostReturnSize = func->returnType.GetSizeInMemoryDWords();
			internal->hostReturnFloat = false;
		}
		else if( objType == asOBJ_FLOAT )
		{
			internal->hostReturnInMemory = false;
			internal->hostReturnSize = func->returnType.GetSizeInMemoryDWords();
			internal->hostReturnFloat = true;
		}
	}
	// Primitive types can easily be determined
	else if( func->returnType.GetSizeInMemoryDWords() > 2 )
	{
		// Shouldn't be possible to get here
		assert(false);

		internal->hostReturnInMemory = true;
		internal->hostReturnSize = 1;
		internal->hostReturnFloat = false;
	}
	else if( func->returnType.GetSizeInMemoryDWords() == 2 )
	{
		internal->hostReturnInMemory = false;
		internal->hostReturnSize = 2;
		internal->hostReturnFloat = func->returnType.IsEqualExceptConst(asCDataType::CreatePrimitive(ttDouble, true));
	}
	else if( func->returnType.GetSizeInMemoryDWords() == 1 )
	{
		internal->hostReturnInMemory = false;
		internal->hostReturnSize = 1;
		internal->hostReturnFloat = func->returnType.IsEqualExceptConst(asCDataType::CreatePrimitive(ttFloat, true));
	}
	else
	{
		internal->hostReturnInMemory = false;
		internal->hostReturnSize = 0;
		internal->hostReturnFloat = false;
	}

	// Calculate the size needed for the parameters
	internal->paramSize = func->GetSpaceNeededForArguments();

	// Verify if the function takes any objects by value
	asUINT n;
	internal->takesObjByVal = false;
	for( n = 0; n < func->parameterTypes.GetLength(); n++ )
	{
		if( func->parameterTypes[n].IsObject() && !func->parameterTypes[n].IsObjectHandle() && !func->parameterTypes[n].IsReference() )
		{
			internal->takesObjByVal = true;
			break;
		}
	}

	// Verify if the function has any registered autohandles
	internal->hasAutoHandles = false;
	for( n = 0; n < internal->paramAutoHandles.GetLength(); n++ )
	{
		if( internal->paramAutoHandles[n] )
		{
			internal->hasAutoHandles = true;
			break;
		}
	}

	return 0;
}

int CallSystemFunction( int id, asCContext *context, void *objectPointer )
{
	asCScriptEngine			   *engine			   = context->engine;
	asCScriptFunction			   *descr			   = engine->scriptFunctions[id];
	asSSystemFunctionInterface *sysFunc			   = engine->scriptFunctions[id]->sysFuncIntf;
	int							callConv		   = sysFunc->callConv;

	asQWORD						retQW			   = 0;
	asQWORD						retQW2			   = 0;
	asQWORD						retFloatBits	   = 0;
	void					   *func			   = ( void * )sysFunc->func;
	// AAPCS64's dedicated indirect-result register (X8) target for
	// return-in-memory calls - kept fully separate from the normal
	// argument classification/sorting below, unlike x86-64 SysV where
	// the hidden return pointer is just an ordinary first integer arg.
	void					   *hiddenRetPtr	   = NULL;
	int							paramSize		   = sysFunc->paramSize;
	// NOTE: this version's asCContext has no nested `.regs` sub-struct -
	// stackPointer/objectRegister/objectType/register1 are direct members.
	asDWORD					   *args			   = context->stackPointer;
	asDWORD					   *stack_pointer	   = context->stackPointer;
	void					   *retPointer		   = 0;
	void					   *obj				   = 0;
	int							popSize			   = paramSize;
	int							totalArgumentCount = 0;
	int							n				   = 0;
	int							base_n			   = 0;
	int							a				   = 0;
	int							param_pre		   = 0;
	int							param_post		   = 0;

	asDWORD	 tempBuff[CALLSTACK_MULTIPLIER * ARM64_CALLSTACK_SIZE] = { 0 };
	asBYTE	 tempType[ARM64_CALLSTACK_SIZE] = { 0 };

	asDWORD	 paramBuffer[CALLSTACK_MULTIPLIER * ARM64_CALLSTACK_SIZE] = { 0 };
	asBYTE	 argsType[ARM64_CALLSTACK_SIZE] = { 0 };

	asBYTE	 argsSet[ARM64_CALLSTACK_SIZE]  = { 0 };

	if( callConv == ICC_GENERIC_FUNC || callConv == ICC_GENERIC_METHOD ) {
		return context->CallGeneric( id, objectPointer );
	}

	context->objectType = descr->returnType.GetObjectType();
	if( descr->returnType.IsObject() && !descr->returnType.IsReference() && !descr->returnType.IsObjectHandle() ) {
		// Allocate the memory for the object
		retPointer = engine->CallAlloc( descr->returnType.GetObjectType() );

		if( sysFunc->hostReturnInMemory ) {
			// The return is made in memory
			callConv++;
		}
	}

	int argumentCount = ( int )descr->parameterTypes.GetLength();
	assert( argumentCount <= ARM64_MAX_ARGS );

	int argIndex = 0;
	for( a = 0; a < argumentCount; ++a, ++argIndex ) {
		argsType[argIndex] = arm64INTARG;
		if ( descr->parameterTypes[a].IsFloatType() && !descr->parameterTypes[a].IsReference() ) {
			argsType[argIndex] = arm64FLOATARG;
		}
		if ( descr->parameterTypes[a].IsDoubleType() && !descr->parameterTypes[a].IsReference() ) {
			argsType[argIndex] = arm64DOUBLEARG;
		}
		if ( descr->parameterTypes[a].GetSizeOnStackDWords() == 2 && !descr->parameterTypes[a].IsDoubleType() && !descr->parameterTypes[a].IsReference() ) {
			argsType[argIndex] = arm64INTARG;
		}
	}
	assert( argIndex == argumentCount );

	for ( a = 0; a < argumentCount && totalArgumentCount <= ARM64_MAX_ARGS; a++ ) {
		if ( totalArgumentCount < ARM64_MAX_ARGS )
			tempType[totalArgumentCount++] = argsType[a];
	}

	assert( totalArgumentCount <= ARM64_MAX_ARGS );
	if ( totalArgumentCount > argumentCount ) {
		memcpy( argsType, tempType, totalArgumentCount );
	}
	memset( tempType, 0, sizeof( tempType ) );

#ifndef COMPLEX_OBJS_PASSED_BY_REF
	if( sysFunc->takesObjByVal ) {
		context->SetInternalException( TXT_INVALID_CALLING_CONVENTION );
		if( retPointer ) {
			engine->CallFree( descr->returnType.GetObjectType(), retPointer );
		}
		return 0;
	}
#endif

	obj = objectPointer;
	if ( !obj && callConv >= ICC_THISCALL ) {
		// The object pointer should be popped from the context stack
		popSize += PTR_SIZE;

		// Check for null pointer
		obj = ( void * )( *( ( asQWORD * )( args ) ) );
		stack_pointer += PTR_SIZE;
		if( !obj ) {
			context->SetInternalException( TXT_NULL_POINTER_ACCESS );
			if( retPointer ) {
				engine->CallFree( descr->returnType.GetObjectType(), retPointer );
			}
			return 0;
		}

		// Add the base offset for multiple inheritance.
		//
		// NOTE: On AArch64, adj stores TWICE the real this-adjustment,
		// plus 1 if the member function is virtual (see the matching
		// comment/fix in as_callfunc.cpp's DetectCallingConvention). This
		// raw, still-encoded word must be decoded back into a real byte
		// adjustment here before being added to a this-pointer directly.
		asQWORD realBaseOffset = ( asQWORD )( sysFunc->baseOffset >> 1 );
		obj = ( void * )( ( asQWORD )obj + realBaseOffset );
	}

	typedef asQWORD ( *funcptr_t )( void );
	funcptr_t *vftable = NULL;
	if ( obj && ( callConv == ICC_VIRTUAL_THISCALL || callConv == ICC_VIRTUAL_THISCALL_RETURNINMEM ) ) {
		vftable = *( ( funcptr_t ** )obj );
		func	= ( void * )vftable[( asQWORD )func >> 3];
	}

	switch ( callConv ) {
		case ICC_CDECL_RETURNINMEM:
		case ICC_STDCALL_RETURNINMEM: {
			// Hidden return pointer -> X8 (see ARM64_CallFunction), NOT a
			// normal argument slot - no shifting of the real arguments
			// needed at all here (unlike the x86-64 SysV reference this
			// was adapted from, which DOES prepend it as arg 0).
			hiddenRetPtr = retPointer;
			break;
		}
		case ICC_THISCALL:
		case ICC_VIRTUAL_THISCALL:
		case ICC_CDECL_OBJFIRST: {
			if ( totalArgumentCount ) {
				memmove( argsType + 1, argsType, totalArgumentCount );
			}
			memcpy( paramBuffer, &obj, sizeof( obj ) );
			argsType[0] = arm64INTARG;

			param_pre = 1;

			break;
		}
		case ICC_THISCALL_RETURNINMEM:
		case ICC_VIRTUAL_THISCALL_RETURNINMEM:
		case ICC_CDECL_OBJFIRST_RETURNINMEM: {
			// Hidden return pointer -> X8 (see above); only `obj` occupies
			// a normal argument slot here (X0), not retPointer too.
			hiddenRetPtr = retPointer;
			if ( totalArgumentCount ) {
				memmove( argsType + 1, argsType, totalArgumentCount );
			}
			memcpy( paramBuffer, &obj, sizeof( obj ) );
			argsType[0] = arm64INTARG;

			param_pre = 1;

			break;
		}
		case ICC_CDECL_OBJLAST: {
			memcpy( paramBuffer + totalArgumentCount * CALLSTACK_MULTIPLIER, &obj, sizeof( obj ) );
			argsType[totalArgumentCount] = arm64INTARG;

			param_post = 1;

			break;
		}
		case ICC_CDECL_OBJLAST_RETURNINMEM: {
			// Hidden return pointer -> X8 (see above); only `obj` occupies
			// a normal argument slot here (appended at the end), not
			// retPointer too.
			hiddenRetPtr = retPointer;
			memcpy( paramBuffer + totalArgumentCount * CALLSTACK_MULTIPLIER, &obj, sizeof( obj ) );
			argsType[totalArgumentCount] = arm64INTARG;

			param_post = 1;

			break;
		}
		default: {
			base_n = 0;
			break;
		}
	}

	for( n = 0; n < ( int )( param_pre + totalArgumentCount + param_post ); n++ ) {
		int copy_count = 0;
		if ( n >= param_pre && n < ( int )( param_pre + totalArgumentCount ) ) {
			copy_count = descr->parameterTypes[n - param_pre].GetSizeOnStackDWords();
		}
		if ( copy_count > CALLSTACK_MULTIPLIER ) {
			if ( copy_count > CALLSTACK_MULTIPLIER + 1 ) {
				context->SetInternalException( TXT_INVALID_CALLING_CONVENTION );
				return 0;
			}

			memcpy( paramBuffer + ( n - 1 ) * CALLSTACK_MULTIPLIER, stack_pointer, PTR_SIZE * sizeof( asDWORD ) );
			stack_pointer += PTR_SIZE;
			memcpy( paramBuffer + n * CALLSTACK_MULTIPLIER, stack_pointer, sizeof( asDWORD ) );
			stack_pointer += 1;
		} else {
			if ( copy_count ) {
				memcpy( paramBuffer + n * CALLSTACK_MULTIPLIER, stack_pointer, copy_count * sizeof( asDWORD ) );
				stack_pointer += copy_count;
			}
		}
	}

	/*
	 * Sort the classified arguments into the fixed layout expected by
	 * ARM64_CallFunction() - see the equivalent comment in the 2.19.2
	 * port for the full explanation of this layout and its correspondence
	 * to the x64 push-based reference implementation.
	 */
	int		used_int_regs = 0;
	int		used_sse_regs = 0;
	int		idx			  = 0;
	base_n = 0;
	for ( n = 0; ( n < ARM64_CALLSTACK_SIZE ) && ( used_int_regs < MAX_CALL_INT_REGISTERS ); n++ ) {
		if ( argsType[n] == arm64INTARG ) {
			idx = base_n;
			argsSet[n] = 1;
			tempType[idx] = argsType[n];
			memcpy( tempBuff + idx * CALLSTACK_MULTIPLIER, paramBuffer + n * CALLSTACK_MULTIPLIER, CALLSTACK_MULTIPLIER * sizeof( asDWORD ) );
			base_n++;
			used_int_regs++;
		}
	}
	base_n = 0;
	for ( n = 0; ( n < ARM64_CALLSTACK_SIZE ) && ( used_sse_regs < MAX_CALL_SSE_REGISTERS ); n++ ) {
		if ( argsType[n] == arm64FLOATARG || argsType[n] == arm64DOUBLEARG ) {
			idx = MAX_CALL_INT_REGISTERS + base_n;
			argsSet[n] = 1;
			tempType[idx] = argsType[n];
			memcpy( tempBuff + idx * CALLSTACK_MULTIPLIER, paramBuffer + n * CALLSTACK_MULTIPLIER, CALLSTACK_MULTIPLIER * sizeof( asDWORD ) );
			base_n++;
			used_sse_regs++;
		}
	}
	base_n = 0;
	for ( n = ARM64_CALLSTACK_SIZE - 1; n >= 0; n-- ) {
		if ( argsType[n] != arm64ENDARG && !argsSet[n] ) {
			idx = MAX_CALL_INT_REGISTERS + MAX_CALL_SSE_REGISTERS + base_n;
			argsSet[n] = 1;
			tempType[idx] = argsType[n];
			memcpy( tempBuff + idx * CALLSTACK_MULTIPLIER, paramBuffer + n * CALLSTACK_MULTIPLIER, CALLSTACK_MULTIPLIER * sizeof( asDWORD ) );
			base_n++;
		}
	}

	context->isCallingSystemFunction = true;
	retQW = ARM64_CallFunction( tempBuff, tempType, ( void * )func, hiddenRetPtr, &retFloatBits, &retQW2 );
	context->isCallingSystemFunction = false;

#ifdef COMPLEX_OBJS_PASSED_BY_REF
	if( sysFunc->takesObjByVal ) {
		// Need to free the complex objects passed by value
		stack_pointer = context->stackPointer;
		if ( !objectPointer && callConv >= ICC_THISCALL ) {
			stack_pointer += PTR_SIZE;
		}
		for( n = 0; n < ( int )descr->parameterTypes.GetLength(); n++ ) {
			if ( descr->parameterTypes[n].IsObject() && !descr->parameterTypes[n].IsReference() && ( descr->parameterTypes[n].GetObjectType()->flags & COMPLEX_MASK ) ) {
				obj = ( void * )( *( asQWORD * )stack_pointer );
				asSTypeBehaviour *beh = &descr->parameterTypes[n].GetObjectType()->beh;
				if( beh->destruct ) {
					engine->CallObjectMethod(obj, beh->destruct);
				}

				engine->CallFree( descr->parameterTypes[n].GetObjectType(), obj );
			}

			stack_pointer += descr->parameterTypes[n].GetSizeOnStackDWords();
		}
	}
#endif

	// Store the returned value in our stack
	if( descr->returnType.IsObject() && !descr->returnType.IsReference() )
	{
		if( descr->returnType.IsObjectHandle() )
		{
			context->objectRegister = ( void * )( size_t )retQW;

			if( sysFunc->returnAutoHandle && context->objectRegister )
			{
				engine->CallObjectMethod( context->objectRegister, descr->returnType.GetObjectType()->beh.addref );
			}
		}
		else
		{
			if ( !sysFunc->hostReturnInMemory )
			{
				if ( sysFunc->hostReturnSize == 1 )
				{
					*( asDWORD * )retPointer = ( asDWORD )retQW;
				}
				else if ( sysFunc->hostReturnSize == 2 )
				{
					*( asQWORD * )retPointer = retQW;
				}
				else if ( sysFunc->hostReturnSize == 3 )
				{
					*( asQWORD * )retPointer			 = retQW;
					*( ( ( asDWORD * )retPointer ) + 2 ) = ( asDWORD )retQW2;
				}
				else
				{
					*( asQWORD * )retPointer			 = retQW;
					*( ( ( asQWORD * )retPointer ) + 1 ) = retQW2;
				}
			}

			// Store the object in the register
			context->objectRegister = retPointer;
		}
	}
	else
	{
		// Store value in register1
		if( sysFunc->hostReturnFloat )
		{
			if( sysFunc->hostReturnSize == 1 )
			{
				// Low 32 bits of D0 hold the float value's raw bits
				*(asDWORD*)&context->register1 = ( asDWORD )retFloatBits;
			}
			else
			{
				context->register1 = retFloatBits;
			}
		}
		else if ( sysFunc->hostReturnSize == 1 )
		{
			*( asDWORD * )&context->register1 = ( asDWORD )retQW;
		}
		else
		{
			context->register1 = retQW;
		}
	}

	if( sysFunc->hasAutoHandles )
	{
		args = context->stackPointer;
		if( callConv >= ICC_THISCALL && !objectPointer )
		{
			args += PTR_SIZE;
		}

		int spos = 0;
		for( n = 0; n < ( int )descr->parameterTypes.GetLength(); n++ )
		{
			if( sysFunc->paramAutoHandles[n] && (*(size_t*)&args[spos] != 0) )
			{
				// Call the release method on the type
				engine->CallObjectMethod( ( void * )*( size_t * )&args[spos], descr->parameterTypes[n].GetObjectType()->beh.release );
				args[spos] = 0;
			}

			if( descr->parameterTypes[n].IsObject() && !descr->parameterTypes[n].IsObjectHandle() && !descr->parameterTypes[n].IsReference() )
			{
				spos += PTR_SIZE;
			}
			else
			{
				spos += descr->parameterTypes[n].GetSizeOnStackDWords();
			}
		}
	}

	return popSize;
}

END_AS_NAMESPACE

#endif // AS_ARM64_GCC
#endif // AS_MAX_PORTABILITY
