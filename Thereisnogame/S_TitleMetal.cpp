#include "PrecompileHeader.h"
#include "S_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

S_TitleMetal::S_TitleMetal()
{
}

S_TitleMetal::~S_TitleMetal()
{

}

void S_TitleMetal::Start()
{
	S_TitleMetals = Init(S_TitleMetals, "TitleMetal_S.png", { 102,138 }, { 280,230,0 });
	S_TitleMetalsCollision = CollisionInit(S_TitleMetalsCollision, { 94,142 }, { 280,230,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void S_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(S_TitleMetalsCollision))
	{
		Play(Sound, "MetalHit.wav", 0.1f);
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void S_TitleMetal::Render(float _Delta)
{

};


