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
	R_Rocks = Init(R_Rocks, "Icon_Shifumi_Rock.png", { 232,350 }, { 0,0,0 });
	R_RocksCollision = CollisionInit(R_RocksCollision, { 232,350 }, { 0,0,0 });
}

void R_Rock::Update(float _DeltaTime)
{

}

void R_Rock::Render(float _Delta)
{

};

