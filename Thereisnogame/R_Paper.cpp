#include "PrecompileHeader.h"
#include "R_Paper.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"
R_Paper::R_Paper()
{
}

R_Paper::~R_Paper()
{
}

void R_Paper::Start()
{
	float4 Position = { -350,-365,0 };
	R_Papers = Init(R_Papers, "Icon_Shifumi_Paper.png", { 232,350 }, Position);
	R_PapersCollision = CollisionInit(R_PapersCollision, { 232,350 }, Position);
	GetTransform()->SetLocalPosition({ 0,-175,0 });
}

void R_Paper::Update(float _DeltaTime)
{
	RoShamboStateCheck(R_PapersCollision);
	if (true == IsPos)
	{
		InfinityShape(_DeltaTime);
	}
}

void R_Paper::Render(float _Delta)
{

};

void R_Paper::Up()
{
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,1,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 0.0f)
	{
		IsPos = true;
	}
}
