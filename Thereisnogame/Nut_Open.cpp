#include "PrecompileHeader.h"
#include "Nut_Open.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core

//Actor
#include "Mouse.h"
#include "LevelStateManager.h"

Nut_Open::Nut_Open()
{
}

Nut_Open::~Nut_Open()
{
}


void Nut_Open::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	Nut_Opens = Init(Nut_Opens, "NutObj_Opened.png", { 64,58 }, Position);
	Nut_Opens_overlap = Init(Nut_Opens_overlap, "NutObj_Opened_Overlap.png", { 96,89 }, { Position.x - 3,Position.y + 3 });

	Nut_OpensCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Nut_Open);
	Nut_OpensCollision->GetTransform()->SetLocalScale({ 64,58 });
	Nut_OpensCollision->GetTransform()->SetLocalPosition(Position);
}

void Nut_Open::Update(float _DeltaTime)
{
	Fall(Nut_Opens, Nut_Opens_overlap, Nut_OpensCollision, 28.0f, _DeltaTime);
	CatchCheck(Nut_Opens, Nut_Opens_overlap, Nut_OpensCollision);
	if (true == LevelStateManager::MG->GetIsGetTheKey())
	{
		Death();
	}
}

void Nut_Open::Render(float _Delta)
{

};
