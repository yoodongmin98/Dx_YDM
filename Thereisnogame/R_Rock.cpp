#include "PrecompileHeader.h"
#include "R_Rock.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_Rock::R_Rock()
{
}

R_Rock::~R_Rock()
{
}

void R_Rock::Start()
{
	float4 Position = {-480,-540,0};
	R_Rocks = Init(R_Rocks, "Icon_Shifumi_Rock.png", { 232,350 }, Position);
	R_RocksCollision = CollisionInit(R_RocksCollision, { 232,350 }, Position);
}

void R_Rock::Update(float _DeltaTime)
{

}

void R_Rock::Render(float _Delta)
{

};

