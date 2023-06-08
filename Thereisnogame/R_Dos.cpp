#include "PrecompileHeader.h"
#include "R_Dos.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_Dos::R_Dos()
{
}

R_Dos::~R_Dos()
{
}

void R_Dos::Start()
{
	R_Doss = Init(R_Doss, "Icon_Shifumi_Voix_Dos.png", { 232,350 }, { 0,0,0 });
	R_DossCollision = CollisionInit(R_DossCollision, { 232,350 }, { 0,0,0 });
}

void R_Dos::Update(float _DeltaTime)
{

}

void R_Dos::Render(float _Delta)
{

};

