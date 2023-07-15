#include "PrecompileHeader.h"
#include "G_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

G_TitleMetal::G_TitleMetal()
{
}

G_TitleMetal::~G_TitleMetal()
{

}

void G_TitleMetal::Start()
{
	G_TitleMetals = Init(G_TitleMetals, "TitleMetal_G.png", { 102,138 }, { -60,80,0 });
	G_TitleMetalsCollision = CollisionInit(G_TitleMetalsCollision, { 94,142 }, { -60,80,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void G_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(G_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void G_TitleMetal::Render(float _Delta)
{

};


