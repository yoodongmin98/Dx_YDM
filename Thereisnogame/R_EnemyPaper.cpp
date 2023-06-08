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
	R_EnemyPapers = Init(R_EnemyPapers, "Icon_Shifumi_Voix_Paper.png", { 232,350 }, { 0,0,0 });
	R_EnemyPapersCollision = CollisionInit(R_EnemyPapersCollision, { 232,350 }, { 0,0,0 });
}

void R_EnemyPaper::Update(float _DeltaTime)
{

}

void R_EnemyPaper::Render(float _Delta)
{

};

