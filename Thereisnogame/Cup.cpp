#include "PrecompileHeader.h"
#include "Cup.h"
#include "ActorTypeEnum.h"

//PlatForm
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
	float4 Position = { 300,0,0 };
	Cups = Init(Cups, "CupObj_Empty.png", { 94,121 }, Position);
	Cups_Overlap = Init(Cups_Overlap, "CupObj_Empty_Overlap.png", { 126,153 }, { Position.x - 3,Position.y + 3 });
	CupCollision = CollisionInit(CupCollision, { 94,121,1 }, Position);
}

void Cup::Update(float _DeltaTime)
{
	Fall(Cups, Cups_Overlap, CupCollision,60.5f,_DeltaTime);
	CatchCheck(Cups, Cups_Overlap, CupCollision);
	if (CupCollision->Collision(ActorTypeEnum::Picture, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&&true==Mouse::MainMouse->IsInteractable()
		&&true== LevelStateManager::MG->GetIsRain())
	{
		GetLevel()->CreateActor<Cup_Full>();
		Death();
	}
}

void Cup::Render(float _Delta)
{

};
