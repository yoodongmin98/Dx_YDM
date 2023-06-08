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
	float4 Position = { -250,-540,0 };
	R_Sissors = Init(R_Sissors, "Icon_Shifumi_Scissor.png", { 232,350 }, Position);
	R_SissorsCollision = CollisionInit(R_SissorsCollision, { 232,350 }, Position);
}

void R_Sissor::Update(float _DeltaTime)
{
	if (GetLiveTime() > 0.6f)
	{
		InfinityShape(_DeltaTime);
	}
}

void R_Sissor::Render(float _Delta)
{

};

