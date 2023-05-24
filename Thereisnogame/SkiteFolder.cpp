#include "PrecompileHeader.h"
#include "SkiteFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Skite.h"
#include "SkiteBanner.h"
#include "BoxCroix_Skite.h"
#include "LevelStateManager.h"



SkiteFolder::SkiteFolder()
{
}

SkiteFolder::~SkiteFolder()
{
}

void SkiteFolder::Start()
{
	SkiteFolders=Init(SkiteFolders, "Skite.png", { 103,102 }, { -420,200,0 });
	SkiteFoldersCollision = CollisionInit(SkiteFoldersCollision, { 103,102 }, { -420,200,0 });
}

void SkiteFolder::Update(float _DeltaTime)
{
	ManagedCollision(SkiteFoldersCollision, 0);
	if (true == ClickCheck(SkiteFoldersCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		SkitePtr=GetLevel()->CreateActor<Skite>();
		SkiteBannerPtr=GetLevel()->CreateActor<SkiteBanner>();
		BoxCroix_SkitePtr= GetLevel()->CreateActor<BoxCroix_Skite>();
	}
	if (nullptr != BoxCroix_SkitePtr)
	{
		BoxCroixDeathCheck();
	}
}

void SkiteFolder::Render(float _Delta)
{

};

void SkiteFolder::BoxCroixDeathCheck()
{
	if (true == BoxCroix_SkitePtr->IsDeath())
	{
		SkitePtr.get()->Death();
		SkiteBannerPtr.get()->Death();
	}
}