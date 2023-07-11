#include "PrecompileHeader.h"
#include "TrashcanFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "GoodbyeIcon.h"
#include "PasswordIcon.h"
#include "PinBall_Icon.h"
#include "TrashCanFolderPanel.h"
#include "BoxCroix_TrashCanFolder.h"
#include "FolderBackGround.h"

TrashcanFolder::TrashcanFolder()
{
}

TrashcanFolder::~TrashcanFolder()
{
}

void TrashcanFolder::Start()
{
	TrashcanFolderClose=Init(TrashcanFolderClose, "IconRubbish.png", { 63,84 }, { 420,-200,0 });
	TrashcanFolderOpen = Init(TrashcanFolderClose, "IconRubbish_Open.png", { 63,84 }, { 420,-200,0 });

	TrashcanFolderCollision = CollisionInit(TrashcanFolderCollision, { 63,84 }, { 420,-200,0 });
}

void TrashcanFolder::Update(float _DeltaTime)
{
	RenderAndCollisionCheck();
	if (true == ClickCheck(TrashcanFolderCollision))
	{
		Play(Sound, "OpenWindow.wav", 0.1f);
		LevelStateManager::MG->PlusCollisionValue();
		FolderBackGroundPtr = GetLevel()->CreateActor<FolderBackGround>();
		TrashCanFolderPanelPtr = GetLevel()->CreateActor<TrashCanFolderPanel>();
		GoodbyeIconPtr = GetLevel()->CreateActor<GoodbyeIcon>();
		PasswordIconPtr = GetLevel()->CreateActor<PasswordIcon>();
		PinBall_IconPtr = GetLevel()->CreateActor<PinBall_Icon>();
		BoxCroix_TrashCanFolderPtr = GetLevel()->CreateActor<BoxCroix_TrashCanFolder>();
	}
	if (nullptr != BoxCroix_TrashCanFolderPtr)
	{
		BoxCroixDeathCheck();
	}
}

void TrashcanFolder::Render(float _Delta)
{

};



void TrashcanFolder::RenderAndCollisionCheck()
{
	if (true == LevelStateManager::MG->GetIsTrashCanOpen())
	{
		ManagedCollision(TrashcanFolderCollision, 0);
		TrashcanFolderClose->Death();
		TrashcanFolderOpen->On();
	}
	else
	{
		TrashcanFolderCollision->Off();
		TrashcanFolderOpen->Off();
	}
}

void TrashcanFolder::BoxCroixDeathCheck()
{
	if (true == BoxCroix_TrashCanFolderPtr->IsDeath())
	{
		FolderBackGroundPtr.get()->Death();
		TrashCanFolderPanelPtr.get()->Death();
		GoodbyeIconPtr.get()->Death();
		PasswordIconPtr.get()->Death();
		PinBall_IconPtr.get()->Death();
	}
}