#include "PrecompileHeader.h"
#include "Private18.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "PrivatePanel_Miss.h"
#include "FRMissIcon.h"
#include "JPMissIcon.h"
#include "USMissIcon.h"
#include "BoxCroix_PR_Miss.h"

Private18::Private18()
{
}

Private18::~Private18()
{
}

void Private18::Start()
{
	Init(Private18s, "Folder.png", { 96,87 }, {-170,20});
	Private18sCollision = CollisionInit(Private18sCollision, { 96,87 }, { -170,20 });

	Font = FontCreate(Font, 25, "18+", { -170,-40 }, GetTransform(), 2);
	Font1 = FontCreate(Font1, 25, "기가 개인용", { -190,120 }, GetTransform(), 2);
}

void Private18::Update(float _DeltaTime)
{
	ManagedCollision(Private18sCollision, 4);
	if (true == ClickCheck(Private18sCollision))
	{
		Play(Sound, "OpenWindow.wav", 0.1f);
		LevelStateManager::MG->PlusCollisionValue();
		LevelStateManager::MG->Set18OpenTrue();
		PrivatePanel_MissPtr = GetLevel()->CreateActor<PrivatePanel_Miss>();
		BoxCroix_PR_MissPtr = GetLevel()->CreateActor<BoxCroix_PR_Miss>();
		FRMissIconPtr = GetLevel()->CreateActor<FRMissIcon>();
		JPMissIconPtr = GetLevel()->CreateActor<JPMissIcon>();
		USMissIconPtr = GetLevel()->CreateActor<USMissIcon>();
	}
	if (nullptr != BoxCroix_PR_MissPtr)
	{
		BoxCroixDeathCheck();
	}
}

void Private18::Render(float _Delta)
{

};

void Private18::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_MissPtr->IsDeath())
	{
		PrivatePanel_MissPtr.get()->Death();
		FRMissIconPtr.get()->Death();
		JPMissIconPtr.get()->Death();
		USMissIconPtr.get()->Death();
	}
}