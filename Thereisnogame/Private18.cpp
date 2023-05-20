#include "PrecompileHeader.h"
#include "Private18.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"
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
}

void Private18::Update(float _DeltaTime)
{
	ManagedCollision(Private18sCollision, 4);
	if (true == ClickCheck(Private18sCollision))
	{
		ColManager::MG->PlusCollisionValue();
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