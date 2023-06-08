#include "PrecompileHeader.h"
#include "T_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

T_TitleMetal::T_TitleMetal()
{
}

T_TitleMetal::~T_TitleMetal()
{

}

void T_TitleMetal::Start()
{
	T_TitleMetals = Init(T_TitleMetals, "TitleMetal_T.png", { 94,142 }, { -300,230,0 });
	T_TitleMetalsCollision = CollisionInit(T_TitleMetalsCollision, { 94,142 }, { -300,230,0 });
}

void T_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(T_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void T_TitleMetal::Render(float _Delta)
{

};


