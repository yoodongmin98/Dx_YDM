#include "PrecompileHeader.h"
#include "M_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

M_TitleMetal::M_TitleMetal()
{
}

M_TitleMetal::~M_TitleMetal()
{

}

void M_TitleMetal::Start()
{
	M_TitleMetals = Init(M_TitleMetals, "TitleMetal_M.png", { 126,138 }, { 160,80,0 });
	M_TitleMetalsCollision = CollisionInit(M_TitleMetalsCollision, { 94,142 }, { 160,80,0 });
}

void M_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(M_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void M_TitleMetal::Render(float _Delta)
{

};


