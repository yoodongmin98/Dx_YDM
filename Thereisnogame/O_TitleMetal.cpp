#include "PrecompileHeader.h"
#include "O_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

O_TitleMetal::O_TitleMetal()
{
}

O_TitleMetal::~O_TitleMetal()
{

}

void O_TitleMetal::Start()
{
	O_TitleMetals = Init(O_TitleMetals, "TitleMetal_O.png", { 102,138 }, { -200,80,0 });
	O_TitleMetalsCollision = CollisionInit(O_TitleMetalsCollision, { 94,142 }, { -200,80,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void O_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(O_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void O_TitleMetal::Render(float _Delta)
{

};


