#include "PrecompileHeader.h"
#include "ME_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"
#include "LevelStateManager.h"
ME_TitleMetal::ME_TitleMetal()
{
}

ME_TitleMetal::~ME_TitleMetal()
{

}

void ME_TitleMetal::Start()
{
	ME_TitleMetals = Init(ME_TitleMetals, "TitleMetal_E.png", { 99,138 }, { 270,80,0 });
	ME_TitleMetalsCollision = CollisionInit(ME_TitleMetalsCollision, { 94,142 }, { 270,80,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}

void ME_TitleMetal::Update(float _DeltaTime)
{
	if (GetLiveTime() > 1.0f&& true==StateChangeBool)
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::SlantBoard);
		StateChangeBool = false;
	}
	if (true == ClickCheck(ME_TitleMetalsCollision))
	{
		LevelStateManager::MG->SetHMCMetalPlus();
	}
}

void ME_TitleMetal::Render(float _Delta)
{

};


