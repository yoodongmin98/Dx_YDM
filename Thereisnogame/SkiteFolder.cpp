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
#include "SkiteIcon.h"
#include "FolderBackGround.h"



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
		Play(Sound, "OpenWindow.wav", 0.1f);
		LevelStateManager::MG->PlusCollisionValue();
		FolderBackGroundPtr = GetLevel()->CreateActor<FolderBackGround>();
		SkitePtr=GetLevel()->CreateActor<Skite>();
		SkiteBannerPtr=GetLevel()->CreateActor<SkiteBanner>();
		BoxCroix_SkitePtr= GetLevel()->CreateActor<BoxCroix_Skite>();
		if (true == LevelStateManager::MG->Get18OpenTrue())
		{
			SkiteIconPtr= GetLevel()->CreateActor<SkiteIcon>();
		}
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
		FolderBackGroundPtr.get()->Death();
		if (true == LevelStateManager::MG->Get18OpenTrue()
			&& nullptr!=SkiteIconPtr.get())
		{
			SkiteIconPtr.get()->Death();

		}
	}
}