#include "PrecompileHeader.h"
#include "RE_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

RE_TitleMetal::RE_TitleMetal()
{
}

RE_TitleMetal::~RE_TitleMetal()
{

}

void RE_TitleMetal::Start()
{
	RE_TitleMetals = Init(RE_TitleMetals, "TitleMetal_E.png", { 99,138 }, { 60,230,0 });
	RE_TitleMetalsCollision = CollisionInit(RE_TitleMetalsCollision, { 94,142 }, { 60,230,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void RE_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(RE_TitleMetalsCollision))
	{
		Play(Sound, "MetalHit.wav", 0.1f);
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void RE_TitleMetal::Render(float _Delta)
{

};


