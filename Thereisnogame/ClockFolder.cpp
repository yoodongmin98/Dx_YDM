#include "PrecompileHeader.h"
#include "ClockFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "ClockPaddle0.h"
#include "ClockPaddle1.h"
#include "ClockPaddle2.h"
#include "ClockPaddle3.h"
#include "ClockPaddle4.h"
#include "ClockPaddle5.h"
#include "ClockPaddle6.h"
#include "ClockPaddle7.h"
#include "ClockPaddle8.h"
#include "ClockPaddle9.h"
#include "BoxCroix_ClockPanel.h"
#include "ClockUnderBar.h"
#include "ClockDayandNight.h"
#include "BoxCroix_ClockDay.h"
#include "ClockBranch.h"
#include "FolderBackGround.h"

ClockFolder::ClockFolder()
{
}

ClockFolder::~ClockFolder()
{
}

void ClockFolder::Start()
{
	ClockFolder_Night =Init(ClockFolder_Night, "HourOs_Night00.png", { 102,97 }, { 420,200,0 });
	ClockFolder_Day = Init(ClockFolder_Day, "HourOs_Day00.png", { 102,97 }, { 420,200,0 });
	ClockFoldersCollision = CollisionInit(ClockFoldersCollision, { 102,97 }, { 420,200,0 });

	ClockFolder_Day->Off();
}

void ClockFolder::Update(float _DeltaTime)
{
	ManagedCollision(ClockFoldersCollision, 0);
	if (2 == LevelStateManager::MG->GetClockValue())
	{
		ClockFolder_Night->Death();
		ClockFolder_Day->On();
	}
	if (true == ClickCheck(ClockFoldersCollision)&& 0==LevelStateManager::MG->GetClockValue())
	{
		LevelStateManager::MG->PlusCollisionValue();
		FolderBackGroundPtr = GetLevel()->CreateActor<FolderBackGround>();
		ClockPaddle0Ptr=GetLevel()->CreateActor<ClockPaddle0>();
		ClockPaddle1Ptr=GetLevel()->CreateActor<ClockPaddle1>();
		ClockPaddle2Ptr=GetLevel()->CreateActor<ClockPaddle2>();
		ClockPaddle3Ptr=GetLevel()->CreateActor<ClockPaddle3>();
		ClockPaddle4Ptr=GetLevel()->CreateActor<ClockPaddle4>();
		ClockPaddle5Ptr=GetLevel()->CreateActor<ClockPaddle5>();
		ClockPaddle6Ptr=GetLevel()->CreateActor<ClockPaddle6>();
		ClockPaddle7Ptr=GetLevel()->CreateActor<ClockPaddle7>();
		ClockPaddle8Ptr=GetLevel()->CreateActor<ClockPaddle8>();
		ClockPaddle9Ptr=GetLevel()->CreateActor<ClockPaddle9>();
		ClockUnderBarPtr = GetLevel()->CreateActor<ClockUnderBar>();
		BoxCroix_ClockPanelPtr=GetLevel()->CreateActor<BoxCroix_ClockPanel>();
	}
	if (true == ClickCheck(ClockFoldersCollision) && 1 <= LevelStateManager::MG->GetClockValue())
	{
		LevelStateManager::MG->PlusCollisionValue();
		ClockDayandNightPtr = GetLevel()->CreateActor<ClockDayandNight>();
		BoxCroix_ClockDayPtr = GetLevel()->CreateActor<BoxCroix_ClockDay>();
		if (2 != LevelStateManager::MG->GetClockValue())
		{
			ClockBranchPtr = GetLevel()->CreateActor<ClockBranch>();
		}
	}
	if (nullptr != BoxCroix_ClockPanelPtr)
	{
		BoxCroixDeathCheck();
	}
}

void ClockFolder::Render(float _Delta)
{

};

void ClockFolder::BoxCroixDeathCheck()
{
	if (true == BoxCroix_ClockPanelPtr->IsDeath()||true== ClockUnderBarPtr->IsDeath())
	{
		ClockPaddle0Ptr.get()->Death();
		ClockPaddle1Ptr.get()->Death();
		ClockPaddle2Ptr.get()->Death();
		ClockPaddle3Ptr.get()->Death();
		ClockPaddle4Ptr.get()->Death();
		ClockPaddle5Ptr.get()->Death();
		ClockPaddle6Ptr.get()->Death();
		ClockPaddle7Ptr.get()->Death();
		ClockPaddle8Ptr.get()->Death();
		ClockPaddle9Ptr.get()->Death();
		ClockUnderBarPtr.get()->Death();
		FolderBackGroundPtr.get()->Death();
	}
	if (nullptr != BoxCroix_ClockDayPtr)
	{
		if (1 <= LevelStateManager::MG->GetClockValue()
			&& true == BoxCroix_ClockDayPtr->IsDeath())
		{
			ClockDayandNightPtr.get()->Death();
			ClockBranchPtr.get()->Death();
		}

	}
}