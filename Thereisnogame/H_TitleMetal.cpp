#include "PrecompileHeader.h"
#include "H_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

H_TitleMetal::H_TitleMetal()
{
}

H_TitleMetal::~H_TitleMetal()
{

}

void H_TitleMetal::Start()
{
	H_TitleMetals = Init(H_TitleMetals, "TitleMetal_H.png", { 102,138 }, { -210,230,0 });
	H_TitleMetalsCollision = CollisionInit(H_TitleMetalsCollision, { 94,142 }, { -210,230,0 });
}

void H_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(H_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void H_TitleMetal::Render(float _Delta)
{

};


