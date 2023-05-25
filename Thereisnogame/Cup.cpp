#include "PrecompileHeader.h"
#include "Cup.h"
#include "ActorTypeEnum.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
#include "Cup_Full.h"

Cup::Cup()
{
}

Cup::~Cup()
{
}

void Cup::Start()
{
	float4 Position = { 0,0,0 };
	Cups_Overlap = Init(Cups_Overlap, "CupObj_Empty_Overlap.png", { 126,153 }, { Position.x - 3,Position.y + 3 });
	Cups = Init(Cups, "CupObj_Empty.png", { 94,121 }, Position);
	CupCollision = CollisionInit(CupCollision, { 94,121,1 }, Position);
}

void Cup::Update(float _DeltaTime)
{
	CollisionInteractableCheck();
	if (true == LevelStateManager::MG->GetIsGetTheCup())
	{
		Fall(Cups, Cups_Overlap, CupCollision,60.5f,_DeltaTime);
		CatchCheck(Cups, Cups_Overlap, CupCollision);
	}
}

void Cup::Render(float _Delta)
{

};


void Cup::CollisionInteractableCheck()
{
	if (CupCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& GameEngineInput::IsDown("LeftMouse")
		&& false==LevelStateManager::MG->GetIsGetTheCup())
	{
		LevelStateManager::MG->SetIsGetTheCupTrue();
		LevelStateManager::MG->MinusCollisionValue();
	}
	if (CupCollision->Collision(ActorTypeEnum::Picture, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable()
		&& true == LevelStateManager::MG->GetIsRain())
	{
		GetLevel()->CreateActor<Cup_Full>();
		Death();
	}
}