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
#include "impl/PhysicsMaterialNewton.h"

#include "impl/PhysicsWorldNewton.h"
#include "impl/PhysicsBodyNewton.h"
#include "physics/SurfaceData.h"

#include "system/LowLevelSystem.h"
#include <algorithm>

namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cPhysicsMaterialNewton::cPhysicsMaterialNewton(const tString &asName, iPhysicsWorld *apWorld,int alMatId)
		: iPhysicsMaterial(asName,apWorld)
	{
		cPhysicsWorldNewton *pNWorld = static_cast<cPhysicsWorldNewton*>(mpWorld);

		mpNewtonWorld = pNWorld->GetNewtonWorld();

		if(alMatId==-1)
		{
			mlMaterialId = NewtonMaterialCreateGroupID(mpNewtonWorld);
		}
		else
		{
			mlMaterialId = alMatId;
		}

		//Setup default properties
		mFrictionMode = ePhysicsMaterialCombMode_Average;
		mElasticityMode  = ePhysicsMaterialCombMode_Average;

		mfElasticity = 0.5f;
		mfStaticFriction = 0.3f;
		mfKineticFriction = 0.3f;

		//Log(" Created physics material '%s' with Newton id %d\n",asName.c_str(),mlMaterialId);
	}

	//-----------------------------------------------------------------------

	cPhysicsMaterialNewton::~cPhysicsMaterialNewton()
	{
		/*Might be just as well to let newton handle this*/
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	void cPhysicsMaterialNewton::SetElasticity(float afElasticity)
	{
		mfElasticity = afElasticity;

		UpdateMaterials();
	}

	float cPhysicsMaterialNewton::GetElasticity() const
	{
		return mfElasticity;
	}

	//-----------------------------------------------------------------------

	void cPhysicsMaterialNewton::SetStaticFriction(float afElasticity)
	{
		mfStaticFriction = afElasticity;

		UpdateMaterials();
	}

	float cPhysicsMaterialNewton::GetStaticFriction() const
	{
		return mfStaticFriction;
	}

	//-----------------------------------------------------------------------

	void cPhysicsMaterialNewton::SetKineticFriction(float afElasticity)
	{
		mfKineticFriction = afElasticity;

		UpdateMaterials();
	}

	float cPhysicsMaterialNewton::GetKineticFriction() const
	{
		return mfKineticFriction;
	}

	//-----------------------------------------------------------------------

	void cPhysicsMaterialNewton::SetFrictionCombMode(ePhysicsMaterialCombMode aMode)
	{
		mFrictionMode = aMode;

		UpdateMaterials();
	}

	ePhysicsMaterialCombMode cPhysicsMaterialNewton::GetFrictionCombMode() const
	{
		return mFrictionMode;
	}

	//-----------------------------------------------------------------------

	void cPhysicsMaterialNewton::SetElasticityCombMode(ePhysicsMaterialCombMode aMode)
	{
		mElasticityMode = aMode;

		UpdateMaterials();
	}

	//-----------------------------------------------------------------------

	ePhysicsMaterialCombMode cPhysicsMaterialNewton::GetElasticityCombMode() const
	{
		return mElasticityMode;
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	void cPhysicsMaterialNewton::UpdateMaterials()
	{
		cPhysicsMaterialIterator MatIt = mpWorld->GetMaterialIterator();

		while(MatIt.HasNext())
		{
			cPhysicsMaterialNewton* pMat = static_cast<cPhysicsMaterialNewton*>(MatIt.Next());

			ePhysicsMaterialCombMode frictionMode =   (ePhysicsMaterialCombMode) std::max(mFrictionMode,
				pMat->mFrictionMode);
			ePhysicsMaterialCombMode elasticityMode = (ePhysicsMaterialCombMode) std::max(mElasticityMode,
				pMat->mElasticityMode);

			//If the material is the same do not blend.
			if(pMat == this){
				frictionMode = 	ePhysicsMaterialCombMode_Average;
				elasticityMode = ePhysicsMaterialCombMode_Average;
			}


			NewtonMaterialSetDefaultElasticity(mpNewtonWorld,mlMaterialId,pMat->mlMaterialId,
				Combine(elasticityMode,mfElasticity, pMat->mfElasticity));

			NewtonMaterialSetDefaultFriction(mpNewtonWorld,mlMaterialId,pMat->mlMaterialId,
				Combine(frictionMode,mfStaticFriction, pMat->mfStaticFriction),
				Combine(frictionMode,mfKineticFriction, pMat->mfKineticFriction));

			NewtonMaterialSetContinuousCollisionMode(mpNewtonWorld,mlMaterialId,pMat->mlMaterialId,
													1);

			NewtonMaterialSetCollisionCallback(mpNewtonWorld,mlMaterialId,pMat->mlMaterialId,
				(void*)NULL,BeginContactCallback,ProcessContactCallback);

		}
	}

	//-----------------------------------------------------------------------

	float cPhysicsMaterialNewton::Combine(ePhysicsMaterialCombMode aMode, float afX, float afY)
	{
		switch(aMode)
		{
		case ePhysicsMaterialCombMode_Average: return (afX + afY)/2;
		case ePhysicsMaterialCombMode_Min: return std::min(afX, afY);
		case ePhysicsMaterialCombMode_Max: return std::max(afX, afY);
		case ePhysicsMaterialCombMode_Multiply: return afX * afY;
		}

		return (afX + afY) /2;
	}

	//////////////////////////////////////////////////////////////////////////
	// STATIC NEWTON CALLBACKS
	//////////////////////////////////////////////////////////////////////////

	iPhysicsBody *cPhysicsMaterialNewton::mpContactBody1 = NULL;
	iPhysicsBody *cPhysicsMaterialNewton::mpContactBody2 = NULL;
	int cPhysicsMaterialNewton::mlContactNum =0;
	cPhysicsContactData cPhysicsMaterialNewton::mContactData;

	//-----------------------------------------------------------------------
int cPhysicsMaterialNewton::BeginContactCallback(const NewtonMaterial* material,
const NewtonBody* apBody1, const NewtonBody* apBody2, int)
{
mpContactBody1 = (cPhysicsBodyNewton*) NewtonBodyGetUserData(apBody1);
mpContactBody2 = (cPhysicsBodyNewton*) NewtonBodyGetUserData(apBody2);

if(mpContactBody1->GetCollide()==false) return 0;
if(mpContactBody2->GetCollide()==false) return 0;

if(mpContactBody1->IsActive()==false) return 0;
if(mpContactBody2->IsActive()==false) return 0;

if(mpContactBody1->IsRagDoll() && mpContactBody2->GetCollideRagDoll()==false) return 0;
if(mpContactBody2->IsRagDoll() && mpContactBody1->GetCollideRagDoll()==false) return 0;

if(mpContactBody1->IsCharacter() && mpContactBody2->GetCollideCharacter()==false) return 0;
if(mpContactBody2->IsCharacter() && mpContactBody1->GetCollideCharacter()==false) return 0;

// The dynamic paraffin-lamp fixture ("parrafinlight_jointN") has a broken
// joint setup (see the "Child body does not exist" / "Parent body does not
// exist" mesh-loading errors for boat_dynamicparaffin.dae). Whatever pose
// its joint leaves it resting at overlaps the ship's beam geometry, so
// Newton's solver fights a permanent, unresolved deep-penetration contact
// there every frame - observed as a sustained ~5000-unit force versus the
// normal tens/hundreds elsewhere. That's numerically unstable enough to
// potentially disturb the wider simulation even though the beam itself
// can't move. Just don't let this fixture collide with anything until its
// asset/joint data is fixed properly.
if(mpContactBody1->GetName().find("parrafinlight") != tString::npos) return 0;
if(mpContactBody2->GetName().find("parrafinlight") != tString::npos) return 0;

// Same wedged-geometry pattern as the paraffin lamp above: the locker
// door's closed/limit pose overlaps its lock mechanism, so this pair
// fights a permanent unresolved contact every frame (sustained
// ~200-330-unit force at a fixed position vs. the normal single/double
// digits elsewhere). Disable collision between this specific pair rather
// than the whole locker or lock, so the door/lock still collide normally
// with everything else.
{
	const tString &sName1 = mpContactBody1->GetName();
	const tString &sName2 = mpContactBody2->GetName();
	bool bIsLockerDoor1 = sName1.find("lockerdoor") != tString::npos;
	bool bIsLockerDoor2 = sName2.find("lockerdoor") != tString::npos;
	bool bIsLock1 = sName1.find("lock1") != tString::npos && !bIsLockerDoor1;
	bool bIsLock2 = sName2.find("lock1") != tString::npos && !bIsLockerDoor2;
	if((bIsLockerDoor1 && bIsLock2) || (bIsLockerDoor2 && bIsLock1)) return 0;
}

//Reset contact num
mlContactNum =0;

if(mpContactBody1->OnBeginCollision(mpContactBody2)==false) return 0;
if(mpContactBody2->OnBeginCollision(mpContactBody1)==false) return 0;

return 1;
}

//-----------------------------------------------------------------------

void cPhysicsMaterialNewton::ProcessContactCallback(const NewtonJoint* apContactJoint,
dFloat, int)
{
// NOTE: modern Newton invokes this once per contact JOINT (which may
// contain several individual contact points), not once per contact
// directly. Each contact's NewtonMaterial* must be looked up explicitly
// via NewtonContactGetMaterial(). The per-contact query functions also
// simplified from (material, contact) down to just (material).
//
// IMPORTANT: this function used to read mpContactBody1/mpContactBody2 -
// static scratch members stashed by BeginContactCallback - assuming
// Begin and Process run in tight lockstep for the same pair. This
// Newton build's broadphase (dgBroadPhaseMaterialCallbackWorkerThread)
// does not guarantee that: Begin calls for several pairs can all run
// before Process is invoked for any of them, so the static pointers
// could belong to a different pair by the time Process reads them,
// causing an intermittent null-pointer crash here. Fetch the bodies
// directly from the joint instead, and keep all per-call accumulation
// in locals so nothing is shared across calls or threads.
NewtonBody* apNewtonBody1 = NewtonJointGetBody0(apContactJoint);
NewtonBody* apNewtonBody2 = NewtonJointGetBody1(apContactJoint);

iPhysicsBody *pContactBody1 = (iPhysicsBody*) NewtonBodyGetUserData(apNewtonBody1);
iPhysicsBody *pContactBody2 = (iPhysicsBody*) NewtonBodyGetUserData(apNewtonBody2);

if(pContactBody1==NULL || pContactBody2==NULL) return;

cPhysicsContactData localContactData;
int lLocalContactNum = 0;

void* contact = NewtonContactJointGetFirstContact(apContactJoint);
while(contact)
{
NewtonMaterial* apMaterial = NewtonContactGetMaterial(contact);

//Normal speed
float fNormSpeed = NewtonMaterialGetContactNormalSpeed(apMaterial);
if(localContactData.mfMaxContactNormalSpeed < fNormSpeed) localContactData.mfMaxContactNormalSpeed = fNormSpeed;

//Tangent speed
float fTanSpeed0 = NewtonMaterialGetContactTangentSpeed(apMaterial,0);
float fTanSpeed1 = NewtonMaterialGetContactTangentSpeed(apMaterial,1);
if(std::abs(localContactData.mfMaxContactTangentSpeed) < std::abs(fTanSpeed0)) localContactData.mfMaxContactTangentSpeed = fTanSpeed0;
if(std::abs(localContactData.mfMaxContactTangentSpeed) < std::abs(fTanSpeed1)) localContactData.mfMaxContactTangentSpeed = fTanSpeed1;

//Force
cVector3f vForce;
NewtonMaterialGetContactForce(apMaterial,vForce.v);
localContactData.mvForce += vForce;

//Position and normal
cVector3f vPos, vNormal;
NewtonMaterialGetContactPositionAndNormal(apMaterial,vPos.v, vNormal.v);

localContactData.mvContactNormal += vNormal;
localContactData.mvContactPosition += vPos;

if(pContactBody1->GetWorld()->GetSaveContactPoints())
{
cCollidePoint collidePoint;
collidePoint.mfDepth = 1;
NewtonMaterialGetContactPositionAndNormal (apMaterial, collidePoint.mvPoint.v,
collidePoint.mvNormal.v);

pContactBody1->GetWorld()->GetContactPoints()->push_back(collidePoint);
}

lLocalContactNum++;

contact = NewtonContactJointGetNextContact(apContactJoint, contact);
}
		// NOTE: this used to be the separate EndContactCallback logic,
		// invoked once per material-pair after all per-contact Process calls
		// finished. That separate callback slot no longer exists in this
		// Newton version's API, so its logic is merged in here instead -
		// ProcessContactCallback is invoked once per contact JOINT now,
		// matching the same "once per body-pair collision event" granularity
		// that EndContactCallback used to handle.

		if(lLocalContactNum <= 0) return;

		{
			float fForceLen = localContactData.mvForce.Length();
			if(fForceLen > 200.0f || std::abs(localContactData.mfMaxContactNormalSpeed) > 5.0f)
			{
				Log("ANOMALOUS CONTACT: body1='%s' (mass=%f, linVel=%f) body2='%s' (mass=%f, linVel=%f) normalSpeed=%f force=(%f,%f,%f) len=%f pos=(%f,%f,%f)\n",
					pContactBody1->GetName().c_str(), pContactBody1->GetMass(), pContactBody1->GetLinearVelocity().Length(),
					pContactBody2->GetName().c_str(), pContactBody2->GetMass(), pContactBody2->GetLinearVelocity().Length(),
					localContactData.mfMaxContactNormalSpeed,
					localContactData.mvForce.x, localContactData.mvForce.y, localContactData.mvForce.z, fForceLen,
					localContactData.mvContactPosition.x, localContactData.mvContactPosition.y, localContactData.mvContactPosition.z);
			}
		}

		iPhysicsMaterial *pMaterial1 = pContactBody1->GetMaterial();
		iPhysicsMaterial *pMaterial2 = pContactBody2->GetMaterial();

		localContactData.mvContactNormal = localContactData.mvContactNormal / (float)lLocalContactNum;
		localContactData.mvContactPosition = localContactData.mvContactPosition / (float)lLocalContactNum;

		cSurfaceData *pSurface1 = pMaterial1 ? pMaterial1->GetSurfaceData() : NULL;
		cSurfaceData *pSurface2 = pMaterial2 ? pMaterial2->GetSurfaceData() : NULL;

		if(pSurface1 && pSurface2)
		{
			pSurface1->CreateImpactEffect(localContactData.mfMaxContactNormalSpeed,
														localContactData.mvContactPosition,
														lLocalContactNum,pSurface2);

			int lPrio1 = pSurface1->GetPriority();
			int lPrio2 = pSurface2->GetPriority();

			if(lPrio1 >= lPrio2)
			{
				if(std::abs(localContactData.mfMaxContactNormalSpeed) > 0)
					pSurface1->OnImpact(localContactData.mfMaxContactNormalSpeed,
														localContactData.mvContactPosition,
														lLocalContactNum,pContactBody1);
				if(std::abs(localContactData.mfMaxContactTangentSpeed) > 0)
					pSurface1->OnSlide(localContactData.mfMaxContactTangentSpeed,
														localContactData.mvContactPosition,
														lLocalContactNum,pContactBody1,pContactBody2);
			}

			if(lPrio2 >= lPrio1 && pMaterial2 != pMaterial1)
			{
				if(std::abs(localContactData.mfMaxContactNormalSpeed) > 0)
					pSurface2->OnImpact(localContactData.mfMaxContactNormalSpeed,
														localContactData.mvContactPosition,
														lLocalContactNum,pContactBody2);
				if(std::abs(localContactData.mfMaxContactTangentSpeed) > 0)
					pSurface2->OnSlide(localContactData.mfMaxContactTangentSpeed,
														localContactData.mvContactPosition,
														lLocalContactNum,pContactBody2,pContactBody1);
			}
		}

		pContactBody1->OnCollide(pContactBody2,&localContactData);
		pContactBody2->OnCollide(pContactBody1,&localContactData);
	}

	//-----------------------------------------------------------------------

}
