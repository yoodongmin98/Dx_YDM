#include "PrecompileHeader.h"
#include "JPMissIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "ColManager.h"
#include "MissPicture.h"
#include "BoxCroix_PR_MissPicture.h"
#include "LeftRotate.h"
#include "RightRotate.h"


JPMissIcon::JPMissIcon()
{
}

JPMissIcon::~JPMissIcon()
{
}

void JPMissIcon::Start()
{
	Init(JPMissIcons, "PictureBoard03.png", { 90,93 }, {180,10});
	JPMissIconsCollision = CollisionInit(JPMissIconsCollision, { 90,93 }, { 180,10 });
}

void JPMissIcon::Update(float _DeltaTime)
{
	ManagedCollision(JPMissIconsCollision, 5);
	if (true == ClickCheck(JPMissIconsCollision))
	{
		ColManager::MG->PlusCollisionValue();
		MissPicturePtr = GetLevel()->CreateActor<MissPicture>();
		LeftRotatePtr = GetLevel()->CreateActor<LeftRotate>();
		RightRotatePtr = GetLevel()->CreateActor<RightRotate>();
		BoxCroix_PR_MissPicturePtr = GetLevel()->CreateActor<BoxCroix_PR_MissPicture>();
		MissPicture::MP->ChangeMissPicture(3);
	}
	if (nullptr != BoxCroix_PR_MissPicturePtr)
	{
		BoxCroixDeathCheck();
	}
}

void JPMissIcon::Render(float _Delta)
{

};

void JPMissIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_MissPicturePtr->IsDeath())
	{
		MissPicturePtr.get()->Death();
		LeftRotatePtr.get()->Death();
		RightRotatePtr.get()->Death();
	}
}