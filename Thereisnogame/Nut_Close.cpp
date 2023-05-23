#include "PrecompileHeader.h"
#include "Nut_Close.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core



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
	Fall(Nut_Closes, Nut_Closes_overlap, Nut_ClosesCollision, 38.0f, _DeltaTime);
	CatchCheck(Nut_Closes, Nut_Closes_overlap, Nut_ClosesCollision);
}

void Nut_Close::Render(float _Delta)
{

};
