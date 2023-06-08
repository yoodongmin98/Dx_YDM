#include "PrecompileHeader.h"
#include "R_Sissor.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_Sissor::R_Sissor()
{
}

R_Sissor::~R_Sissor()
{
}

void R_Sissor::Start()
{
	float4 Position = { -250,-365,0 };
	R_Sissors = Init(R_Sissors, "Icon_Shifumi_Scissor.png", { 232,350 }, Position);
	R_SissorsCollision = CollisionInit(R_SissorsCollision, { 232,350 }, Position);
	GetTransform()->SetLocalPosition({ 0,-175,0 });
}

void R_Sissor::Update(float _DeltaTime)
{
	if (true == IsPos)
	{
		InfinityShape(_DeltaTime);
	}
}

void R_Sissor::Render(float _Delta)
{

};

void R_Sissor::Up()
{
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,1,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 5.0f)
	{
		float4 Tests = GetTransform()->GetLocalPosition();
		GetTransform()->SetLocalPosition(GetTransform()->GetLocalPosition());
		IsPos = true;
	}
}
