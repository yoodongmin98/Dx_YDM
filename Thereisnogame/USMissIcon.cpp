#include "PrecompileHeader.h"
#include "USMissIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "MissPicture.h"
#include "BoxCroix_PR_MissPicture.h"
#include "LeftRotate.h"
#include "RightRotate.h"



USMissIcon::USMissIcon()
{
}

USMissIcon::~USMissIcon()
{
}

void USMissIcon::Start()
{
	Init(USMissIcons, "PictureBoard01 #75136.png", { 90,93 }, {-140,10});
	USMissIconsCollision = CollisionInit(USMissIconsCollision, { 90,93,1 }, { -140,10 });

	Font = FontCreate(Font, 25, "US__MISS", { -145,-40 }, GetTransform(), 2);
	Font1 = FontCreate(Font1, 25, "FR__MISS", { 20,-40 }, GetTransform(), 2);
	Font2 = FontCreate(Font2, 25, "JP__MISS", { 180,-40 }, GetTransform(), 2);
	Font3 = FontCreate(Font3, 25, "18+", { -205,120 }, GetTransform(), 2);
}

void USMissIcon::Update(float _DeltaTime)
{
	ManagedCollision(USMissIconsCollision, 5);
	if (true == ClickCheck(USMissIconsCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		MissPicturePtr=GetLevel()->CreateActor<MissPicture>();
		LeftRotatePtr = GetLevel()->CreateActor<LeftRotate>();
		RightRotatePtr = GetLevel()->CreateActor<RightRotate>();
		BoxCroix_PR_MissPicturePtr = GetLevel()->CreateActor<BoxCroix_PR_MissPicture>();
		MissPicture::MP->ChangeMissPicture(1);
	}
	if (nullptr != BoxCroix_PR_MissPicturePtr)
	{
		BoxCroixDeathCheck();
	}
}

void USMissIcon::Render(float _Delta)
{

};

void USMissIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_MissPicturePtr->IsDeath())
	{
		MissPicturePtr.get()->Death();
		LeftRotatePtr.get()->Death();
		RightRotatePtr.get()->Death();
	}
}