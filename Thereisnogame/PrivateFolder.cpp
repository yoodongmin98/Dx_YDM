#include "PrecompileHeader.h"
#include "PrivateFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "SuperPrivate.h"
#include "Truth1Icon.h"
#include "PrivatePanel.h"
#include "BoxCroix_PR_Super.h"
#include "SkiteCalling.h"
#include "SkiteCallingMissed.h"
#include "FolderBackGround.h"

PrivateFolder::PrivateFolder()
{
}

PrivateFolder::~PrivateFolder()
{
}

void PrivateFolder::Start()
{
	Init(PrivateFolders, "Folder.png", { 96,87 }, { 225,-200,0 });
	PrivateFoldersCollision = CollisionInit(PrivateFoldersCollision, { 96,87 }, { 225,-200,0 });
	Font = FontCreate(Font, 28, "°³ÀÎ¿ë", { 225,-260,0 }, GetTransform(), 2);
}

void PrivateFolder::Update(float _DeltaTime)
{
	ManagedCollision(PrivateFoldersCollision, 0);
	if (true == ClickCheck(PrivateFoldersCollision))
	{
		Play(Sound, "OpenWindow.wav", 0.1f);
		LevelStateManager::MG->PlusCollisionValue();
		FolderBackGroundPtr = GetLevel()->CreateActor<FolderBackGround>();
		PrivatePanelPtr = GetLevel()->CreateActor<PrivatePanel>();
		SuperPrivatePtr = GetLevel()->CreateActor<SuperPrivate>();
		Truth1IconPtr = GetLevel()->CreateActor<Truth1Icon>();
		BoxCroix_PR_SuperPtr= GetLevel()->CreateActor<BoxCroix_PR_Super>();
	}
	if (nullptr != BoxCroix_PR_SuperPtr)
	{
		BoxCroixDeathCheck();
	}
}

void PrivateFolder::Render(float _Delta)
{

};
bool CallingCreate = true;
void PrivateFolder::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_SuperPtr->IsDeath())
	{
		PrivatePanelPtr.get()->Death();
		SuperPrivatePtr.get()->Death();
		Truth1IconPtr.get()->Death();
		FolderBackGroundPtr.get()->Death();
		if (true == LevelStateManager::MG->Get18OpenTrue()
			&&true== CallingCreate)
		{
			LevelStateManager::MG->PlusCollisionValue();
			SkiteCallingPtr = GetLevel()->CreateActor<SkiteCalling>();
			SkiteCallingMissedPtr = GetLevel()->CreateActor<SkiteCallingMissed>(101);
			CallingCreate = false;
		}
	}
}