#include "PrecompileHeader.h"
#include "FRMissIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "ColManager.h"
#include "MissPicture.h"
#include "BoxCroix_PR_MissPicture.h"
#include "LeftRotate.h"
#include "RightRotate.h"

FRMissIcon::FRMissIcon()
{
}

FRMissIcon::~FRMissIcon()
{
}

void FRMissIcon::Start()
{
	Init(FRMissIcons, "PictureBoard02 #75254.png", { 90,93 }, {20,10});
	FRMissIconsCollision = CollisionInit(FRMissIconsCollision, { 90,93 }, { 20,10 });
}

void FRMissIcon::Update(float _DeltaTime)
{
	ManagedCollision(FRMissIconsCollision, 5);
	if (true == ClickCheck(FRMissIconsCollision))
	{
		ColManager::MG->PlusCollisionValue();
		MissPicturePtr = GetLevel()->CreateActor<MissPicture>();
		LeftRotatePtr = GetLevel()->CreateActor<LeftRotate>();
		RightRotatePtr = GetLevel()->CreateActor<RightRotate>();
		BoxCroix_PR_MissPicturePtr = GetLevel()->CreateActor<BoxCroix_PR_MissPicture>();
		MissPicture::MP->ChangeMissPicture(2);
	}
	if (nullptr != BoxCroix_PR_MissPicturePtr)
	{
		BoxCroixDeathCheck();
	}
}

void FRMissIcon::Render(float _Delta)
{

};

void FRMissIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_MissPicturePtr->IsDeath())
	{
		MissPicturePtr.get()->Death();
		LeftRotatePtr.get()->Death();
		RightRotatePtr.get()->Death();
	}
}