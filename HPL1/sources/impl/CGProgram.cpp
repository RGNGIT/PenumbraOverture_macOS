/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of HPL1 Engine.
 *
 * HPL1 Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HPL1 Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HPL1 Engine.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "impl/CGProgram.h"
#include "impl/SDLTexture.h"
#include "system/LowLevelSystem.h"
#include "system/String.h"
#include "math/Math.h"

#include <hlsl2glsl.h>

#include <fstream>
#include <sstream>

namespace hpl{

	//////////////////////////////////////////////////////////////////////////
	// STATIC MEMBERS
	//////////////////////////////////////////////////////////////////////////

	cCGProgram *cCGProgram::gpCurrentVertexProgram = NULL;
	cCGProgram *cCGProgram::gpCurrentFragmentProgram = NULL;
	std::map<std::pair<unsigned int,unsigned int>, unsigned int> cCGProgram::gmapLinkedPrograms;

	static bool gbHlsl2GlslInited = false;

	static void EnsureHlsl2GlslInited()
	{
		if(gbHlsl2GlslInited) return;
		Hlsl2Glsl_Initialize(NULL, NULL, NULL);
		gbHlsl2GlslInited = true;
	}

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cCGProgram::cCGProgram(tString asName, eGpuProgramType aType)
	: iGpuProgram(asName, aType)
	{
		mShaderObject = 0;
		mbCompiledOk = false;
	}

	cCGProgram::~cCGProgram()
	{
		if(gpCurrentVertexProgram == this) gpCurrentVertexProgram = NULL;
		if(gpCurrentFragmentProgram == this) gpCurrentFragmentProgram = NULL;

		if(mShaderObject) glDeleteShader(mShaderObject);
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	bool cCGProgram::Reload()
	{
		return false;
	}

	//-----------------------------------------------------------------------

	void cCGProgram::Unload()
	{
	}

	//-----------------------------------------------------------------------

	void cCGProgram::Destroy()
	{
	}

	//-----------------------------------------------------------------------

	bool cCGProgram::CreateFromFile(const tString &asFile, const tString &asEntry)
	{
		EnsureHlsl2GlslInited();

		//////////////////////////////////
		// Read the whole .cg source file as text.
		std::ifstream file(asFile.c_str(), std::ios::in | std::ios::binary);
		if(!file.is_open())
		{
			Log("Could not open cg file '%s'!\n", asFile.c_str());
			return false;
		}
		std::stringstream buffer;
		buffer << file.rdbuf();
		tString sSource = buffer.str();
		file.close();

		//////////////////////////////////
		// Translate Cg -> GLSL
		EShLanguage lang = (mProgramType == eGpuProgramType_Vertex) ? EShLangVertex : EShLangFragment;
		ShHandle handle = Hlsl2Glsl_ConstructCompiler(lang);
		if(handle == 0)
		{
			Log("Could not construct Cg->GLSL compiler for '%s'!\n", asFile.c_str());
			return false;
		}

		// "cgProfile" here just tells the translator which family of Cg
		// profile conventions/intrinsics to expect in the source - these old
		// HPL1 shaders were originally targeted at arbvp1/arbfp1 (the
		// simplest, most widely supported ARB assembly profiles), so that's
		// the safest choice regardless of what a real Cg compiler would have
		// picked on the original hardware.
		const char *pCgProfile = (mProgramType == eGpuProgramType_Vertex) ? "arbvp1" : "arbfp1";

		int ok = Hlsl2Glsl_Parse(handle, sSource.c_str(), pCgProfile, ETargetGLSL_120, ETranslateOpNone);
		if(!ok)
		{
			Log("Could not parse cg file '%s'!\n", asFile.c_str());
			const char *pLog = Hlsl2Glsl_GetInfoLog(handle);
			if(pLog) Log(" %s\n", pLog);
			Hlsl2Glsl_DestructCompiler(handle);
			return false;
		}

		ok = Hlsl2Glsl_Translate(handle, asEntry.c_str(), ETargetGLSL_120, ETranslateOpNone);
		if(!ok)
		{
			Log("Could not translate cg file '%s' (entry '%s') to GLSL!\n", asFile.c_str(), asEntry.c_str());
			const char *pLog = Hlsl2Glsl_GetInfoLog(handle);
			if(pLog) Log(" %s\n", pLog);
			Hlsl2Glsl_DestructCompiler(handle);
			return false;
		}

		tString sGLSL = Hlsl2Glsl_GetShader(handle);

		//////////////////////////////////
		// Look for texture-unit uniforms (the old TEXUNITn semantic
		// convention), same idea as the previous Cg-parameter-semantic scan.
		for(int i=0; i<MAX_TEXTUREUNITS; ++i) mvTexUnitName[i] = "";
		mvSamplerUnits.clear();

		int lUniformCount = Hlsl2Glsl_GetUniformCount(handle);
		const ShUniformInfo *pUniforms = Hlsl2Glsl_GetUniformInfo(handle);
		for(int i=0; i<lUniformCount; ++i)
		{
			const ShUniformInfo &uniform = pUniforms[i];
			bool bIsSampler =	uniform.type == EShTypeSampler ||
								uniform.type == EShTypeSampler1D ||
								uniform.type == EShTypeSampler2D ||
								uniform.type == EShTypeSampler3D ||
								uniform.type == EShTypeSamplerCube ||
								uniform.type == EShTypeSamplerRect;
			if(!bIsSampler) continue;

			int lUnit = i; // fallback: assign in declaration order
			if(uniform.semantic && strncmp(uniform.semantic, "TEXUNIT", 7) == 0)
			{
				lUnit = atoi(uniform.semantic + 7);
			}
			if(lUnit >= 0 && lUnit < MAX_TEXTUREUNITS)
			{
				mvTexUnitName[lUnit] = uniform.name;
			}

			mvSamplerUnits.push_back(std::pair<tString,int>(tString(uniform.name), lUnit));
		}

		Hlsl2Glsl_DestructCompiler(handle);

		//////////////////////////////////
		// Compile the translated GLSL with plain OpenGL.
		GLenum glType = (mProgramType == eGpuProgramType_Vertex) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
		mShaderObject = glCreateShader(glType);

		const char *pGLSLSrc = sGLSL.c_str();
		glShaderSource(mShaderObject, 1, &pGLSLSrc, NULL);
		glCompileShader(mShaderObject);

		GLint lCompiled = 0;
		glGetShaderiv(mShaderObject, GL_COMPILE_STATUS, &lCompiled);
		if(lCompiled == GL_FALSE)
		{
			GLint lLogLen = 0;
			glGetShaderiv(mShaderObject, GL_INFO_LOG_LENGTH, &lLogLen);
			if(lLogLen > 1)
			{
				char *pLog = new char[lLogLen];
				glGetShaderInfoLog(mShaderObject, lLogLen, NULL, pLog);
				// Log() uses a fixed 2048-byte stack buffer with an
				// unchecked vsprintf internally - a long info log (many
				// errors, or one with long identifier names) can overflow
				// it and crash the whole process. Cap what we pass in.
				tString sSafeLog(pLog);
				if(sSafeLog.size() > 1800) sSafeLog = sSafeLog.substr(0, 1800) + "...(truncated)";
				Log("GLSL compile error in '%s':\n%s\n", asFile.c_str(), sSafeLog.c_str());
				delete[] pLog;
			}
			else
			{
				Log("GLSL compile error in '%s' (no info log available)\n", asFile.c_str());
			}

			if(mbDebugInfo)
			{
				tString sSafeSrc = sGLSL;
				if(sSafeSrc.size() > 1800) sSafeSrc = sSafeSrc.substr(0, 1800) + "...(truncated, see /tmp dump if needed)";
				Log(" ---- Translated GLSL source for '%s' ----\n%s\n ---------------------------------------\n",
					asFile.c_str(), sSafeSrc.c_str());
			}

			glDeleteShader(mShaderObject);
			mShaderObject = 0;
			return false;
		}

		msFile = asFile;
		msEntry = asEntry;
		mbCompiledOk = true;

		Log("CGProgram: compiled OK '%s' (%s, entry '%s')\n", asFile.c_str(),
			mProgramType == eGpuProgramType_Vertex ? "vertex" : "fragment", asEntry.c_str());

		return true;
	}

	//-----------------------------------------------------------------------

	void cCGProgram::Bind()
	{
		if(mProgramType == eGpuProgramType_Vertex)
			gpCurrentVertexProgram = this;
		else
			gpCurrentFragmentProgram = this;

		MakeActivePairCurrent();
	}

	//-----------------------------------------------------------------------

	void cCGProgram::UnBind()
	{
		// The renderer's state-caching logic (iRenderState::SetVtxProgMode/
		// SetFragProgMode) mirrors real Cg's "sticky" binding behavior: once
		// bound, a program stays considered active GL-side across many draws
		// until explicitly replaced. The two stages call UnBind() with
		// different intent though:
		//  - the VERTEX side only calls UnBind() when genuinely switching to
		//    "no vertex program at all" (fully fixed-function) - a reliable
		//    signal that GL should stop using any shader.
		//  - the FRAGMENT side calls UnBind() on every ordinary fragment
		//    program change, even when the vertex program is untouched and
		//    still meant to stay "stuck" bound - resetting GL state here
		//    would fight that assumption and leave later draws with no
		//    program active even though the engine's own bookkeeping still
		//    thinks a program is bound.
		// So only the vertex-side UnBind() actually resets GL state; the
		// fragment side just clears its own "currently remembered" pointer
		// (without touching GL state) so a following vertex-only material
		// doesn't accidentally get paired with a stale fragment program left
		// over from whatever used a fragment shader before it. The next
		// Bind() (on either stage) is what actually (re-)establishes the
		// correct active linked program.
		if(mProgramType == eGpuProgramType_Vertex)
		{
			glUseProgram(0);
			gpCurrentVertexProgram = NULL;
			gpCurrentFragmentProgram = NULL;
		}
		else
		{
			if(gpCurrentFragmentProgram == this) gpCurrentFragmentProgram = NULL;
		}
	}

	//-----------------------------------------------------------------------

	bool  cCGProgram::SetFloat(const tString& asName, float afX)
	{
		StorePendingUniform(asName, 1, afX);

		unsigned int lProg = GetOrLinkCurrentProgram();

		ApplyToAllLinkedPrograms(asName, [afX](GLint lLoc){ glUniform1f(lLoc, afX); });

		return lProg != 0;
	}

	//-----------------------------------------------------------------------

	bool  cCGProgram::SetVec2f(const tString& asName, float afX,float afY)
	{
		StorePendingUniform(asName, 2, afX, afY);

		unsigned int lProg = GetOrLinkCurrentProgram();

		ApplyToAllLinkedPrograms(asName, [afX,afY](GLint lLoc){ glUniform2f(lLoc, afX, afY); });

		return lProg != 0;
	}

	//-----------------------------------------------------------------------

	bool  cCGProgram::SetVec3f(const tString& asName, float afX,float afY,float afZ)
	{
		StorePendingUniform(asName, 3, afX, afY, afZ);

		unsigned int lProg = GetOrLinkCurrentProgram();
		bool bIsLightParam = (asName == "LightPos" || asName == "LightDirMul" || asName == "EyePos");

		ApplyToAllLinkedPrograms(asName, [afX,afY,afZ](GLint lLoc){ glUniform3f(lLoc, afX, afY, afZ); });

		if(bIsLightParam)
		{
			Log("SetVec3f('%s'): stored + applied to all linked programs (current=%u) = (%f, %f, %f)\n",
				asName.c_str(), lProg, afX, afY, afZ);
		}

		return lProg != 0;
	}

	//-----------------------------------------------------------------------

	bool  cCGProgram::SetVec4f(const tString& asName, float afX,float afY,float afZ, float afW)
	{
		StorePendingUniform(asName, 4, afX, afY, afZ, afW);

		unsigned int lProg = GetOrLinkCurrentProgram();

		ApplyToAllLinkedPrograms(asName, [afX,afY,afZ,afW](GLint lLoc){ glUniform4f(lLoc, afX, afY, afZ, afW); });

		return lProg != 0;
	}

	//-----------------------------------------------------------------------

	bool cCGProgram::SetMatrixf(const tString& asName, const cMatrixf& mMtx)
	{
		mmapPendingMatrixUniforms[asName] = mMtx;

		unsigned int lProg = GetOrLinkCurrentProgram();

		// cMatrixf is row-major; GLSL uniform matrices are column-major by
		// default, so transpose=GL_TRUE tells GL to do the flip for us.
		ApplyToAllLinkedPrograms(asName, [&mMtx](GLint lLoc){ glUniformMatrix4fv(lLoc, 1, GL_TRUE, &mMtx.m[0][0]); });

		return lProg != 0;
	}

	//-----------------------------------------------------------------------

	bool cCGProgram::SetMatrixf(const tString& asName, eGpuProgramMatrix mType,
		eGpuProgramMatrixOp mOp)
	{
		bool bIsWVP = (asName == "worldViewProj" || asName == "spotViewProj");

		// Fetch the requested "state matrix" from OpenGL's fixed-function
		// matrix stack, exactly like Cg's cgGLSetStateMatrixParameter used
		// to do automatically - the rest of this renderer still maintains
		// that stack via glMatrixMode/glLoadMatrixf for its own drawing, so
		// it always reflects the current view/projection/texture matrix.
		float mfGLMatrix[16];
		cMatrixf mtx;

		switch(mType)
		{
			case eGpuProgramMatrix_View:
				glGetFloatv(GL_MODELVIEW_MATRIX, mfGLMatrix);
				break;
			case eGpuProgramMatrix_Projection:
				glGetFloatv(GL_PROJECTION_MATRIX, mfGLMatrix);
				break;
			case eGpuProgramMatrix_Texture:
				glGetFloatv(GL_TEXTURE_MATRIX, mfGLMatrix);
				break;
			case eGpuProgramMatrix_ViewProjection:
			{
				float mfModelView[16];
				float mfProj[16];
				glGetFloatv(GL_MODELVIEW_MATRIX, mfModelView);
				glGetFloatv(GL_PROJECTION_MATRIX, mfProj);

				cMatrixf mtxMV, mtxP;
				mtxMV.FromTranspose(mfModelView); // GL matrices are column-major
				mtxP.FromTranspose(mfProj);
				mtx = cMath::MatrixMul(mtxP, mtxMV);

				for(int i=0;i<16;++i) mfGLMatrix[i] = 0;
				break;
			}
			default:
				return false;
		}

		if(mType != eGpuProgramMatrix_ViewProjection)
		{
			// GL's glGetFloatv returns column-major data; cMatrixf is
			// row-major, so FromTranspose() does the right conversion.
			mtx.FromTranspose(mfGLMatrix);
		}

		switch(mOp)
		{
			case eGpuProgramMatrixOp_Identity:
				break;
			case eGpuProgramMatrixOp_Inverse:
				mtx = cMath::MatrixInverse(mtx);
				break;
			case eGpuProgramMatrixOp_Transpose:
				mtx = mtx.GetTranspose();
				break;
			case eGpuProgramMatrixOp_InverseTranspose:
				mtx = cMath::MatrixInverse(mtx).GetTranspose();
				break;
		}

		mmapPendingMatrixUniforms[asName] = mtx;

		unsigned int lProg = GetOrLinkCurrentProgram();

		ApplyToAllLinkedPrograms(asName, [&mtx](GLint lLoc){ glUniformMatrix4fv(lLoc, 1, GL_TRUE, &mtx.m[0][0]); });

		if(bIsWVP)
		{
			static int lLogCount = 0;
			if(lLogCount < 5)
			{
				lLogCount++;
				Log("SetMatrixf('%s'): stored + applied to all linked programs (current=%u), row0=(%f,%f,%f,%f)\n",
					asName.c_str(), lProg, mtx.m[0][0], mtx.m[0][1], mtx.m[0][2], mtx.m[0][3]);
			}
		}

		return lProg != 0;
	}

	//-----------------------------------------------------------------------

	bool cCGProgram::SetTexture(const tString& asName,iTexture* apTexture, bool abAutoDisable)
	{
		unsigned int lProg = GetOrLinkCurrentProgram();
		if(lProg == 0) return false;

		GLint lLoc = glGetUniformLocation(lProg, asName.c_str());
		if(lLoc < 0) return false;

		// There's no separate "disable" concept for a GLSL sampler uniform
		// the way Cg had cgGLDisableTextureParameter - if apTexture is NULL
		// there's simply nothing new to bind, so just leave whatever was
		// already bound to that unit/uniform alone.
		if(apTexture == NULL) return true;

		cSDLTexture* pSDLTex = static_cast<cSDLTexture*>(apTexture);

		// Use a texture unit derived from the uniform location so different
		// samplers in the same program don't collide; this mirrors the old
		// per-parameter unit assignment closely enough for this engine's
		// (small, fixed) number of samplers per shader.
		int lUnit = lLoc;
		if(lUnit >= MAX_TEXTUREUNITS) lUnit = 0;

		glActiveTexture(GL_TEXTURE0 + lUnit);
		GLenum glTarget;
		switch(apTexture->GetTarget())
		{
			case eTextureTarget_1D:		glTarget = GL_TEXTURE_1D; break;
			case eTextureTarget_3D:		glTarget = GL_TEXTURE_3D; break;
			case eTextureTarget_CubeMap:	glTarget = GL_TEXTURE_CUBE_MAP; break;
			case eTextureTarget_Rect:		glTarget = GL_TEXTURE_RECTANGLE_ARB; break;
			case eTextureTarget_2D:
			default:						glTarget = GL_TEXTURE_2D; break;
		}
		glBindTexture(glTarget, pSDLTex->GetTextureHandle());

		glUniform1i(lLoc, lUnit);

		return true;
	}

	//-----------------------------------------------------------------------

	bool cCGProgram::SetTextureToUnit(int alUnit, iTexture* apTexture)
	{
		if(alUnit < 0 || alUnit >= MAX_TEXTUREUNITS) return false;
		if(mvTexUnitName[alUnit] == "") return false;

		return SetTexture(mvTexUnitName[alUnit], apTexture);
	}


	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PROTECTED METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	void cCGProgram::StorePendingUniform(const tString &asName, int alArity, float afX, float afY, float afZ, float afW)
	{
		sPendingUniform &val = mmapPendingUniforms[asName];
		val.mlArity = alArity;
		val.mfVal[0] = afX; val.mfVal[1] = afY; val.mfVal[2] = afZ; val.mfVal[3] = afW;
	}

	//-----------------------------------------------------------------------

	void cCGProgram::ReplayPendingUniforms(cCGProgram *apProgram, unsigned int alGLProgram)
	{
		if(apProgram == NULL || alGLProgram == 0) return;

		std::map<tString, sPendingUniform>::iterator it = apProgram->mmapPendingUniforms.begin();
		for(; it != apProgram->mmapPendingUniforms.end(); ++it)
		{
			GLint lLoc = glGetUniformLocation(alGLProgram, it->first.c_str());
			if(lLoc < 0) continue;

			const sPendingUniform &val = it->second;
			switch(val.mlArity)
			{
				case 1: glUniform1f(lLoc, val.mfVal[0]); break;
				case 2: glUniform2f(lLoc, val.mfVal[0], val.mfVal[1]); break;
				case 3: glUniform3f(lLoc, val.mfVal[0], val.mfVal[1], val.mfVal[2]); break;
				case 4: glUniform4f(lLoc, val.mfVal[0], val.mfVal[1], val.mfVal[2], val.mfVal[3]); break;
			}
		}

		std::map<tString, cMatrixf>::iterator itMtx = apProgram->mmapPendingMatrixUniforms.begin();
		for(; itMtx != apProgram->mmapPendingMatrixUniforms.end(); ++itMtx)
		{
			GLint lLoc = glGetUniformLocation(alGLProgram, itMtx->first.c_str());
			if(lLoc < 0) continue;

			glUniformMatrix4fv(lLoc, 1, GL_TRUE, &itMtx->second.m[0][0]);
		}
	}

	//-----------------------------------------------------------------------

	void cCGProgram::MakeActivePairCurrent()
	{
		unsigned int lProg = GetOrLinkCurrentProgram();
		if(lProg != 0)
		{
			glUseProgram(lProg);

			static int lErrLogCount = 0;
			GLenum err = glGetError();
			if(err != GL_NO_ERROR && lErrLogCount < 30)
			{
				lErrLogCount++;
				Log("GL ERROR after glUseProgram(%u): 0x%x\n", lProg, (unsigned int)err);
			}
		}
	}

	//-----------------------------------------------------------------------

	unsigned int cCGProgram::GetOrLinkCurrentProgram()
	{
		// Not every material pairs a Cg vertex program with a Cg fragment
		// program - some (e.g. the plain ambient/diffuse pass) only use a
		// programmable vertex stage and rely on the fixed-function pipeline
		// for fragment/texture combining, which is a perfectly valid GLSL
		// program (link with only a vertex shader attached - the fragment
		// stage falls back to fixed-function texturing automatically in a
		// compatibility-profile context). Build a cache key that reflects
		// whichever stage(s) are actually present instead of requiring both.
		bool bHaveVS = (gpCurrentVertexProgram != NULL && gpCurrentVertexProgram->mbCompiledOk);
		bool bHaveFS = (gpCurrentFragmentProgram != NULL && gpCurrentFragmentProgram->mbCompiledOk);

		if(!bHaveVS && !bHaveFS) return 0;

		unsigned int lVS = bHaveVS ? gpCurrentVertexProgram->mShaderObject : 0;
		unsigned int lFS = bHaveFS ? gpCurrentFragmentProgram->mShaderObject : 0;

		std::pair<unsigned int,unsigned int> key(lVS, lFS);
		std::map<std::pair<unsigned int,unsigned int>, unsigned int>::iterator it = gmapLinkedPrograms.find(key);
		if(it != gmapLinkedPrograms.end()) return it->second;

		GLuint lProgram = glCreateProgram();
		if(bHaveVS) glAttachShader(lProgram, lVS);
		if(bHaveFS) glAttachShader(lProgram, lFS);
		glLinkProgram(lProgram);

		GLint lLinked = 0;
		glGetProgramiv(lProgram, GL_LINK_STATUS, &lLinked);
		if(lLinked == GL_FALSE)
		{
			GLint lLogLen = 0;
			glGetProgramiv(lProgram, GL_INFO_LOG_LENGTH, &lLogLen);
			if(lLogLen > 1)
			{
				char *pLog = new char[lLogLen];
				glGetProgramInfoLog(lProgram, lLogLen, NULL, pLog);
				tString sSafeLog(pLog);
				if(sSafeLog.size() > 1700) sSafeLog = sSafeLog.substr(0, 1700) + "...(truncated)";
				Log("GLSL link error ('%s' + '%s'):\n%s\n",
					bHaveVS ? gpCurrentVertexProgram->msFile.c_str() : "(none)",
					bHaveFS ? gpCurrentFragmentProgram->msFile.c_str() : "(none)", sSafeLog.c_str());
				delete[] pLog;
			}
			glDeleteProgram(lProgram);
			lProgram = 0;
		}
		else
		{
			Log("CGProgram: linked OK ('%s' + '%s') -> GL program %u\n",
				bHaveVS ? gpCurrentVertexProgram->msFile.c_str() : "(none)",
				bHaveFS ? gpCurrentFragmentProgram->msFile.c_str() : "(none)", (unsigned int)lProgram);

			// Replay any uniform values already set on either side before
			// this exact pairing existed - see the comment on
			// ApplyToAllLinkedPrograms for why this is necessary.
			GLint lPrevProgram = 0;
			glGetIntegerv(GL_CURRENT_PROGRAM, &lPrevProgram);
			glUseProgram(lProgram);
			if(bHaveVS) ReplayPendingUniforms(gpCurrentVertexProgram, lProgram);
			if(bHaveFS) ReplayPendingUniforms(gpCurrentFragmentProgram, lProgram);

			// Tell each sampler uniform which texture unit to actually read
			// from - see the comment on mvSamplerUnits for why this can't
			// just be left at GLSL's default (unit 0) for every sampler.
			if(bHaveVS)
			{
				for(size_t i=0; i<gpCurrentVertexProgram->mvSamplerUnits.size(); ++i)
				{
					GLint lLoc = glGetUniformLocation(lProgram, gpCurrentVertexProgram->mvSamplerUnits[i].first.c_str());
					if(lLoc >= 0) glUniform1i(lLoc, gpCurrentVertexProgram->mvSamplerUnits[i].second);
				}
			}
			if(bHaveFS)
			{
				for(size_t i=0; i<gpCurrentFragmentProgram->mvSamplerUnits.size(); ++i)
				{
					GLint lLoc = glGetUniformLocation(lProgram, gpCurrentFragmentProgram->mvSamplerUnits[i].first.c_str());
					if(lLoc >= 0) glUniform1i(lLoc, gpCurrentFragmentProgram->mvSamplerUnits[i].second);
				}
			}

			glUseProgram(lPrevProgram);
		}

		gmapLinkedPrograms[key] = lProgram;
		return lProgram;
	}

	//-----------------------------------------------------------------------

}
