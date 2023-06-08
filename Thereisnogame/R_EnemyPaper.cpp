#include "PrecompileHeader.h"
#include "R_EnemyPaper.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_EnemyPaper::R_EnemyPaper()
{
}

R_EnemyPaper::~R_EnemyPaper()
{
}

void R_EnemyPaper::Start()
{
	float4 Position = { 500,-540,0 };
	R_EnemyPapers = Init(R_EnemyPapers, "Icon_Shifumi_Voix_Paper.png", { 232,350 }, Position);
	R_EnemyPapersCollision = CollisionInit(R_EnemyPapersCollision, { 232,350 }, Position);
	Off();
}

void R_EnemyPaper::Update(float _DeltaTime)
{

}

void R_EnemyPaper::Render(float _Delta)
{

};

