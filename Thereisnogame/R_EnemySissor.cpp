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
	R_EnemySissors = Init(R_EnemySissors, "Icon_Shifumi_Voix_Scissor.png", { 232,350 }, { 0,0,0 });
	R_EnemySissorsNone = Init(R_EnemySissorsNone, "Icon_Shifumi_Voix_FaceEmpty.png", { 245,362 }, { 0,0,0 });
	R_EnemySissorsCollision = CollisionInit(R_EnemySissorsCollision, { 232,350 }, { 0,0,0 });

	R_EnemySissorsNone->Off();
}

void R_EnemySissor::Update(float _DeltaTime)
{

}

void R_EnemySissor::Render(float _Delta)
{

};

