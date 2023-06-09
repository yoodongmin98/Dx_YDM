#include "PrecompileHeader.h"
#include "I_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

I_TitleMetal::I_TitleMetal()
{
}

I_TitleMetal::~I_TitleMetal()
{

}

void I_TitleMetal::Start()
{
	I_TitleMetals = Init(I_TitleMetals, "TitleMetal_I.png", { 42,138 }, { 190,230,0 });
	I_TitleMetalsCollision = CollisionInit(I_TitleMetalsCollision, { 94,142 }, { 190,230,0 });
}

void I_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(I_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void I_TitleMetal::Render(float _Delta)
{

};


