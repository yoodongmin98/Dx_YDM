#include "PrecompileHeader.h"
#include "Nut_Close.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
#include "Nut_Open.h"

Nut_Close::Nut_Close()
{
}

Nut_Close::~Nut_Close()
{
}

void Nut_Close::Start()
{
	float4 Position = float4::Zero;
	Nut_Closes = Init(Nut_Closes, "NutObj_Closed.png", { 70,76 }, Position);
	Nut_Closes_overlap = Init(Nut_Closes_overlap, "NutObj_Closed_Overlap.png", { 116,121 }, { Position.x - 3,Position.y + 3 });

	Nut_ClosesCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Nut_Close);
	Nut_ClosesCollision->GetTransform()->SetLocalScale({ 70,76 });
	Nut_ClosesCollision->GetTransform()->SetLocalPosition(Position);
}

void Nut_Close::Update(float _DeltaTime)
{
	Fall(Nut_Closes, Nut_Closes_overlap, Nut_ClosesCollision, 37.0f, _DeltaTime);
	CatchCheck(Nut_Closes, Nut_Closes_overlap, Nut_ClosesCollision);
	CollisionInteractableCheck();
}

void Nut_Close::Render(float _Delta)
{

};
bool IsNutopen = false;
void Nut_Close::CollisionInteractableCheck()
{
	//얘도 중복생성되서 렉이 조금 걸리는게 아닐까?
	if (Nut_ClosesCollision->Collision(ActorTypeEnum::Picture, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable()
		&& true == LevelStateManager::MG->GetIsWalNut())
	{
		if (false == IsNutopen)
		{
			GetLevel()->CreateActor<Nut_Open>();
			IsNutopen = true;
			Death();
		}
	}
}