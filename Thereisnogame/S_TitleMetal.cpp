#include "PrecompileHeader.h"
#include "S_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

S_TitleMetal::S_TitleMetal()
{
}

S_TitleMetal::~S_TitleMetal()
{

}

void S_TitleMetal::Start()
{
	S_TitleMetals = Init(S_TitleMetals, "TitleMetal_S.png", { 102,138 }, { 280,230,0 });
	S_TitleMetalsCollision = BlockCollisionInit(S_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void S_TitleMetal::Update(float _DeltaTime)
{
	if (true == ClickCheck(S_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void S_TitleMetal::Render(float _Delta)
{

};


