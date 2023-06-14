#include "PrecompileHeader.h"
#include "T_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"

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
bool T_TitleMetalStateBool = true;
void T_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(T_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
	if (5 < LevelStateManager::MG->GetHMCMetal()
		&&true== T_TitleMetalStateBool)
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::Roshambo);
		T_TitleMetalStateBool = false;
	}
}

void T_TitleMetal::Render(float _Delta)
{

};


