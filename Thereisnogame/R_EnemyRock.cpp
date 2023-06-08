#include "PrecompileHeader.h"
#include "R_EnemyRock.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_EnemyRock::R_EnemyRock()
{
}

R_EnemyRock::~R_EnemyRock()
{
}

void R_EnemyRock::Start()
{
	R_EnemyRocks = Init(R_EnemyRocks, "Icon_Shifumi_Voix_Rock.png", { 232,350 }, { 0,0,0 });
	R_EnemyRocksCollision = CollisionInit(R_EnemyRocksCollision, { 232,350 }, { 0,0,0 });
}

void R_EnemyRock::Update(float _DeltaTime)
{

}

void R_EnemyRock::Render(float _Delta)
{

};

