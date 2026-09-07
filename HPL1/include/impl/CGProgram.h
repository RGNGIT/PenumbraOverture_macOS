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
/*
 * ARM64/macOS NOTE:
 * NVIDIA's Cg Toolkit runtime was never built for ARM64 (Cg was
 * discontinued in 2012, years before Apple Silicon existed, and its
 * compiler was never open-sourced), so there is no way to run real Cg
 * shaders on this platform. This implementation instead translates each
 * .cg shader source to GLSL at load time (via the Cg2glsl / hlsl2glslfork
 * translator, see external/Cg2glsl) and compiles/links/binds the result
 * using plain OpenGL 2.0 shader API calls (glCreateShader, glUseProgram,
 * glUniform*, etc.) instead of any Cg runtime call.
 *
 * One important difference from Cg's model: Cg's old ARB-profile-based
 * binding let a vertex program and a fragment program be bound
 * independently (like two separate assembly programs), whereas GLSL
 * requires a vertex shader and a fragment shader to be linked together
 * into a single program object before use. Since the rest of the engine
 * still creates/binds vertex and fragment cCGProgram instances
 * independently (one iGpuProgram object per stage), this class keeps a
 * small cache mapping (vertex shader, fragment shader) pairs to their
 * linked GL program object, built lazily the first time a given pair is
 * used together.
 */
#ifndef HPL_CGPROGRAM_H
#define HPL_CGPROGRAM_H

#include <GL/GLee.h>

#include <map>
#include <vector>
#include <utility>

#include "system/SystemTypes.h"
#include "math/MathTypes.h"
#include "graphics/GPUProgram.h"

namespace hpl {

	class cCGProgram : public iGpuProgram
	{
	public:
		cCGProgram(tString asName, eGpuProgramType aType);
		~cCGProgram();

		bool Reload();
		void Unload();
		void Destroy();

		tString GetProgramName(){ return msName; }

		bool CreateFromFile(const tString& asFile, const tString& asEntry="main");

		void Bind();
		void UnBind();

		bool SetFloat(const tString& asName, float afX);
		bool SetVec2f(const tString& asName, float afX,float afY);
		bool SetVec3f(const tString& asName, float afX,float afY,float afZ);
		bool SetVec4f(const tString& asName, float afX,float afY,float afZ, float afW);

		bool SetMatrixf(const tString& asName, const cMatrixf& mMtx);
		bool SetMatrixf(const tString& asName, eGpuProgramMatrix mType,
									eGpuProgramMatrixOp mOp);

		bool SetTexture(const tString& asName,iTexture* apTexture, bool abAutoDisable=true);
		bool SetTextureToUnit(int alUnit, iTexture* apTexture);

		/// Kept for source compatibility with old Cg-based force-profile UI/config
		/// code elsewhere in the engine. No-ops here: there is no such thing as
		/// a "profile" to force when the backend is plain GLSL.
		static void SetVProfile(tString){}
		static void SetFProfile(tString){}
		static tString &GetVProfile(){ static tString s = "GLSL"; return s; }
		static tString &GetFProfile(){ static tString s = "GLSL"; return s; }

	protected:
		tString msFile;
		tString msEntry;

		/// This stage's own compiled (not yet linked) GL shader object -
		/// GL_VERTEX_SHADER or GL_FRAGMENT_SHADER depending on mProgramType.
		unsigned int mShaderObject;

		bool mbCompiledOk;

		/// Texture-unit parameter name lookup, mirroring the old TEXUNITn
		/// semantic convention: mvTexUnitName[n] is the uniform name to bind
		/// when SetTextureToUnit(n, ...) is called.
		tString mvTexUnitName[MAX_TEXTUREUNITS];

		/// Sampler uniforms this shader declares, paired with the texture
		/// unit each should read from (from an explicit TEXUNITn semantic,
		/// or its declaration order as a fallback). This old engine's
		/// post-effect shaders in particular get their textures bound
		/// directly by unit number via iLowLevelGraphics::SetTexture()
		/// rather than through any cCGProgram texture-parameter call, so
		/// nothing else ever tells the GLSL sampler uniform itself which
		/// unit to read from - and a sampler uniform silently defaults to
		/// unit 0 if never explicitly set via glUniform1i, meaning every
		/// such sampler in a shader would otherwise read the same texture
		/// regardless of what was actually bound where. Filled in at
		/// compile time, applied once right after a fresh link.
		std::vector<std::pair<tString,int> > mvSamplerUnits;

		/// Last value passed to SetFloat/SetVec2f/SetVec3f/SetVec4f for a
		/// given uniform name (arity = vector length, 1-4), replayed onto
		/// any newly-linked program this shader object ends up paired into
		/// later - without this, a uniform set once (e.g. "LightColor" set
		/// right after this stage's own Bind(), before its partner stage for
		/// the same material has necessarily been (re-)bound yet) could miss
		/// a pairing that doesn't exist in the link cache yet at the moment
		/// it was set.
		struct sPendingUniform { int mlArity; float mfVal[4]; };
		std::map<tString, sPendingUniform> mmapPendingUniforms;

		std::map<tString, cMatrixf> mmapPendingMatrixUniforms;

		void StorePendingUniform(const tString &asName, int alArity, float afX, float afY=0, float afZ=0, float afW=0);
		static void ReplayPendingUniforms(cCGProgram *apProgram, unsigned int alGLProgram);

		void MakeActivePairCurrent();
		unsigned int GetOrLinkCurrentProgram();

		/// glUniform*() (the classic, non-"program"-suffixed API this old GL
		/// context is limited to) always applies to whichever program is
		/// CURRENTLY ACTIVE via glUseProgram - not to an arbitrary program ID
		/// you merely looked up a location on. Since a given vertex (or
		/// fragment) shader object can end up linked into several different
		/// pairs (paired with different partners for different materials),
		/// and the pair that's actually "current" at the moment a SetXxx()
		/// call happens can be a transient/incomplete one (e.g. right after
		/// only this stage was just (re-)bound, before its partner stage for
		/// this same material gets bound moments later), setting a uniform
		/// on "whatever's active right now" can silently miss the pairing
		/// that ends up actually being drawn with. This finds every already-
		/// linked program that includes this shader object and applies the
		/// given uniform-setting callback to each of them, restoring
		/// whatever GL program was active beforehand.
		template<typename SetUniformFunc>
		void ApplyToAllLinkedPrograms(const tString &asName, SetUniformFunc aSetFunc)
		{
			GLint lPrevProgram = 0;
			glGetIntegerv(GL_CURRENT_PROGRAM, &lPrevProgram);

			bool bIsVertex = (mProgramType == eGpuProgramType_Vertex);

			std::map<std::pair<unsigned int,unsigned int>, unsigned int>::iterator it = gmapLinkedPrograms.begin();
			for(; it != gmapLinkedPrograms.end(); ++it)
			{
				unsigned int lKeyShader = bIsVertex ? it->first.first : it->first.second;
				if(lKeyShader != mShaderObject) continue;

				unsigned int lProgram = it->second;
				if(lProgram == 0) continue;

				GLint lLoc = glGetUniformLocation(lProgram, asName.c_str());
				if(lLoc < 0) continue;

				glUseProgram(lProgram);
				aSetFunc(lLoc);
			}

			glUseProgram(lPrevProgram);
		}

		/// The vertex/fragment cCGProgram most recently Bind()-ed - tracked
		/// globally since GLSL needs both halves of a pair to actually link
		/// and use a program, but the engine binds each stage independently.
		static cCGProgram *gpCurrentVertexProgram;
		static cCGProgram *gpCurrentFragmentProgram;

		/// Cache of already-linked GL program objects for a given
		/// (vertex shader object, fragment shader object) pair, so the same
		/// pairing doesn't get re-linked every time it's used again.
		static std::map<std::pair<unsigned int,unsigned int>, unsigned int> gmapLinkedPrograms;
	};
};
#endif // HPL_CGPROGRAM_H
