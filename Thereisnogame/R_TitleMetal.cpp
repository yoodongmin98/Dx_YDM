#include "PrecompileHeader.h"
#include "R_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

R_TitleMetal::R_TitleMetal()
{
}

R_TitleMetal::~R_TitleMetal()
{

}

void R_TitleMetal::Start()
{
	R_TitleMetals = Init(R_TitleMetals, "TitleMetal_R.png", { 102,138 }, { -30,230,0 });
	R_TitleMetalsCollision = CollisionInit(R_TitleMetalsCollision, { 94,142 }, { -30,230,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void R_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(R_TitleMetalsCollision))
	{
		Play(Sound, "MetalHit.wav", 0.1f);
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void R_TitleMetal::Render(float _Delta)
{

};


