#include "PrecompileHeader.h"
#include "A_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

A_TitleMetal::A_TitleMetal()
{
}

A_TitleMetal::~A_TitleMetal()
{

}

void A_TitleMetal::Start()
{
	A_TitleMetals = Init(A_TitleMetals, "TitleMetal_A.png", { 120,138 }, { 40,80,0 });
	A_TitleMetalsCollision = BlockCollisionInit(A_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void A_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(A_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void A_TitleMetal::Render(float _Delta)
{

};


