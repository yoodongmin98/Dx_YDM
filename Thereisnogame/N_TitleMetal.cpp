#include "PrecompileHeader.h"
#include "N_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

N_TitleMetal::N_TitleMetal()
{
}

N_TitleMetal::~N_TitleMetal()
{

}

void N_TitleMetal::Start()
{
	N_TitleMetals = Init(N_TitleMetals, "TitleMetal_N.png", { 102,138 }, { -300,80,0 });
	N_TitleMetalsCollision = CollisionInit(N_TitleMetalsCollision, { 94,142 }, { -300,80,0 });
}

void N_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(N_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void N_TitleMetal::Render(float _Delta)
{

};


