#include "PrecompileHeader.h"
#include "E_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

E_TitleMetal::E_TitleMetal()
{
}

E_TitleMetal::~E_TitleMetal()
{

}

void E_TitleMetal::Start()
{
	E_TitleMetals = Init(E_TitleMetals, "TitleMetal_E.png", { 99,138 }, { -120,230,0 });
	E_TitleMetalsCollision = CollisionInit(E_TitleMetalsCollision, { 94,142 }, { -120,230,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void E_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(E_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void E_TitleMetal::Render(float _Delta)
{

};


