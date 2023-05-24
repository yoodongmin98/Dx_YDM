#include "PrecompileHeader.h"
#include "TrashcanFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"
#include "GoodbyeIcon.h"
#include "PasswordIcon.h"
#include "PinBall_Icon.h"
#include "TrashCanFolderPanel.h"
#include "BoxCroix_TrashCanFolder.h"

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
	//Test¿ë
	TrashcanFolderCollision->On();
	//RenderAndCollisionCheck();
	if (true == ClickCheck(TrashcanFolderCollision))
	{
		ColManager::MG->PlusCollisionValue();
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
	if (true == ColManager::MG->GetIsTrashCanOpen())
	{
		ManagedCollision(TrashcanFolderCollision, 0);
		TrashcanFolderClose->Death();
		TrashcanFolderOpen->On();
		TrashcanFolderCollision->On();
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
		TrashCanFolderPanelPtr.get()->Death();
		GoodbyeIconPtr.get()->Death();
		PasswordIconPtr.get()->Death();
		PinBall_IconPtr.get()->Death();
	}
}