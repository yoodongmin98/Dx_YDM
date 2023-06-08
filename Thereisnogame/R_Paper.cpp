#include "PrecompileHeader.h"
#include "R_Paper.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_Paper::R_Paper()
{
}

R_Paper::~R_Paper()
{
}

void R_Paper::Start()
{
	R_Papers = Init(R_Papers, "Icon_Shifumi_Paper.png", { 232,350 }, { 0,0,0 });
	R_PapersCollision = CollisionInit(R_PapersCollision, { 232,350 }, { 0,0,0 });
}

void R_Paper::Update(float _DeltaTime)
{

}

void R_Paper::Render(float _Delta)
{

};

