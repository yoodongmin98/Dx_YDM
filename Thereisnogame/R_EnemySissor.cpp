#include "PrecompileHeader.h"
#include "R_EnemySissor.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_EnemySissor::R_EnemySissor()
{
}

R_EnemySissor::~R_EnemySissor()
{
}

void R_EnemySissor::Start()
{
	float4 Position = { 500,-540,0 };
	R_EnemySissors = Init(R_EnemySissors, "Icon_Shifumi_Voix_Scissor.png", { 232,350 }, Position);
	R_EnemySissorsNone = Init(R_EnemySissorsNone, "Icon_Shifumi_Voix_FaceEmpty.png", { 245,362 }, Position);
	R_EnemySissorsCollision = CollisionInit(R_EnemySissorsCollision, { 232,350 }, Position);

	Off();
}

void R_EnemySissor::Update(float _DeltaTime)
{

}

void R_EnemySissor::Render(float _Delta)
{

};

