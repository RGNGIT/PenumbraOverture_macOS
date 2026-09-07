#ifndef CG_STUB_CG_H
#define CG_STUB_CG_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CGcontext_st*   CGcontext;
typedef struct CGprogram_st*   CGprogram;
typedef struct CGparameter_st* CGparameter;
typedef struct CGeffect_st*    CGeffect;
typedef struct CGtechnique_st* CGtechnique;
typedef struct CGpass_st*      CGpass;
typedef struct CGstate_st*     CGstate;
typedef struct CGstateassignment_st* CGstateassignment;
typedef struct CGannotation_st* CGannotation;

typedef int CGbool;
typedef int CGprofile;
typedef int CGtype;
typedef int CGparameterclass;
typedef int CGerror;
typedef int CGenum;
typedef int CGresource;
typedef int CGGLenum;

#define CG_NO_ERROR                 0

#define CG_UNKNOWN_TYPE             0
#define CG_FLOAT                    100
#define CG_FLOAT2                   101
#define CG_FLOAT3                   102
#define CG_FLOAT4                   103
#define CG_FLOAT4x4                  104
#define CG_SAMPLER1D                110
#define CG_SAMPLER2D                111
#define CG_SAMPLERCUBE              112
#define CG_SAMPLERRECT              113
#define CG_PROGRAM_TYPE             120

#define CG_PARAMETERCLASS_UNKNOWN   0
#define CG_PARAMETERCLASS_SAMPLER   1

#define CG_SOURCE                   1
#define CG_OBJECT                   2
#define CG_PROGRAM                  3

#define CG_PROFILE_UNKNOWN          0
#define CG_PROFILE_ARBVP1           1
#define CG_PROFILE_VP40             2
#define CG_PROFILE_VP30             3
#define CG_PROFILE_VP20             4
#define CG_PROFILE_GLSLV            5
#define CG_PROFILE_ARBFP1           6
#define CG_PROFILE_FP40             7
#define CG_PROFILE_FP30             8
#define CG_PROFILE_FP20             9
#define CG_PROFILE_GLSLF            10
#define CG_PROFILE_GLSLC          11

static inline CGcontext cgCreateContext(void) { return (CGcontext)0; }
static inline void cgDestroyContext(CGcontext) {}
static inline CGbool cgIsContext(CGcontext) { return 0; }

static inline CGprogram cgCreateProgramFromFile(
	CGcontext, CGenum, const char*, CGprofile, const char*, const char* const*)
{
	return (CGprogram)0;
}
static inline void cgDestroyProgram(CGprogram) {}

static inline CGparameter cgGetFirstParameter(CGprogram, CGenum) { return (CGparameter)0; }
static inline CGparameter cgGetNextParameter(CGparameter) { return (CGparameter)0; }
static inline CGparameter cgGetNamedParameter(CGprogram, const char*) { return (CGparameter)0; }
static inline const char* cgGetParameterName(CGparameter) { return ""; }
static inline const char* cgGetParameterSemantic(CGparameter) { return ""; }
static inline CGtype cgGetParameterType(CGparameter) { return CG_UNKNOWN_TYPE; }
static inline CGparameterclass cgGetParameterClass(CGparameter) { return CG_PARAMETERCLASS_UNKNOWN; }

static inline CGerror cgGetError(void) { return CG_NO_ERROR; }
static inline const char* cgGetErrorString(CGerror) { return "Cg is not available on this platform (stub)"; }
static inline const char* cgGetLastListing(CGcontext) { return ""; }

static inline const char* cgGetProfileString(CGprofile) { return "unknown (Cg stub)"; }

#ifdef __cplusplus
}
#endif

#endif
