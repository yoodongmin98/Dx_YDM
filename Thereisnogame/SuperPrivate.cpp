#include "PrecompileHeader.h"
#include "SuperPrivate.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "PrivatePanel_Ultra.h"
#include "Truth2Icon.h"
#include "UltraPrivate.h"
#include "BoxCroix_PR_Ultra.h"
SuperPrivate::SuperPrivate()
{
}

SuperPrivate::~SuperPrivate()
{
}

void SuperPrivate::Start()
{
	SuperPrivates=Init(SuperPrivates, "Folder.png", { 96,87 }, {-260,20});
	SuperPrivatesCollision = CollisionInit(SuperPrivatesCollision, { 96,87,1 }, { -260,20 });
}

void SuperPrivate::Update(float _DeltaTime)
{
	ManagedCollision(SuperPrivatesCollision, 1);
	if (true == ClickCheck(SuperPrivatesCollision))
	{
		Play(Sound, "OpenWindow.wav", 0.1f);
		LevelStateManager::MG->PlusCollisionValue();
		PrivatePanel_UltraPtr = GetLevel()->CreateActor<PrivatePanel_Ultra>();
		Truth2IconPtr	=GetLevel()->CreateActor<Truth2Icon>();
		UltraPrivatePtr	=GetLevel()->CreateActor<UltraPrivate>();
		BoxCroix_PR_UltraPtr = GetLevel()->CreateActor<BoxCroix_PR_Ultra>();
	}
	if (nullptr != BoxCroix_PR_UltraPtr)
	{
		BoxCroixDeathCheck();
	}
}

void SuperPrivate::Render(float _Delta)
{

};

void SuperPrivate::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_UltraPtr->IsDeath())
	{
		PrivatePanel_UltraPtr.get()->Death();
		UltraPrivatePtr.get()->Death();
		Truth2IconPtr.get()->Death();
	}
}