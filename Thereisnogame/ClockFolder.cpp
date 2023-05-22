#include "PrecompileHeader.h"
#include "ClockFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "ColManager.h"
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

ClockFolder::ClockFolder()
{
}

ClockFolder::~ClockFolder()
{
}

void ClockFolder::Start()
{
	Init(ClockFolders, "HourOs_Night00.png", { 102,97 }, { 420,200,0 });
	ClockFoldersCollision = CollisionInit(ClockFoldersCollision, { 102,97 }, { 420,200,0 });
}

void ClockFolder::Update(float _DeltaTime)
{
	ManagedCollision(ClockFoldersCollision, 0);
	if (true == ClickCheck(ClockFoldersCollision))
	{
		ColManager::MG->PlusCollisionValue();
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
		BoxCroix_ClockPanelPtr=GetLevel()->CreateActor<BoxCroix_ClockPanel>();
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
	if (true == BoxCroix_ClockPanelPtr->IsDeath())
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
	}
}