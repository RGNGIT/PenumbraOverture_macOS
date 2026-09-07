#ifndef CG_STUB_CGGL_H
#define CG_STUB_CGGL_H

#include <Cg/cg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CG_GL_VERTEX                     1
#define CG_GL_FRAGMENT                   2

#define CG_GL_MATRIX_IDENTITY            0
#define CG_GL_MATRIX_TRANSPOSE           1
#define CG_GL_MATRIX_INVERSE             2
#define CG_GL_MATRIX_INVERSE_TRANSPOSE   3

#define CG_GL_MODELVIEW_MATRIX           10
#define CG_GL_PROJECTION_MATRIX          11
#define CG_GL_TEXTURE_MATRIX             12
#define CG_GL_MODELVIEW_PROJECTION_MATRIX 13

static inline CGprofile cgGLGetLatestProfile(CGGLenum) { return CG_PROFILE_UNKNOWN; }
static inline CGbool cgGLIsProfileSupported(CGprofile) { return 0; }
static inline void cgGLSetOptimalOptions(CGprofile) {}
static inline void cgGLEnableProfile(CGprofile) {}
static inline void cgGLDisableProfile(CGprofile) {}

static inline void cgGLLoadProgram(CGprogram) {}
static inline void cgGLBindProgram(CGprogram) {}

static inline void cgGLEnableTextureParameter(CGparameter) {}
static inline void cgGLDisableTextureParameter(CGparameter) {}
static inline void cgGLSetTextureParameter(CGparameter, unsigned int) {}

static inline void cgGLSetMatrixParameterfr(CGparameter, const float*) {}

static inline void cgGLSetParameter1f(CGparameter, float) {}
static inline void cgGLSetParameter2f(CGparameter, float, float) {}
static inline void cgGLSetParameter3f(CGparameter, float, float, float) {}
static inline void cgGLSetParameter4f(CGparameter, float, float, float, float) {}
static inline void cgGLSetStateMatrixParameter(CGparameter, CGGLenum, CGGLenum) {}

#ifdef __cplusplus
}
#endif

#endif
