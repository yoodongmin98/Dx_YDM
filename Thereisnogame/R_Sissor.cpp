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
	R_Sissors = Init(R_Sissors, "Icon_Shifumi_Scissor.png", { 232,350 }, { 0,0,0 });
	R_SissorsCollision = CollisionInit(R_SissorsCollision, { 232,350 }, { 0,0,0 });
}

void R_Sissor::Update(float _DeltaTime)
{
	
}

void R_Sissor::Render(float _Delta)
{

};

