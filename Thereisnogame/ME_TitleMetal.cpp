#include "PrecompileHeader.h"
#include "ME_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

ME_TitleMetal::ME_TitleMetal()
{
}

ME_TitleMetal::~ME_TitleMetal()
{

}

void ME_TitleMetal::Start()
{
	ME_TitleMetals = Init(ME_TitleMetals, "TitleMetal_E.png", { 99,138 }, { 270,80,0 });
	ME_TitleMetalsCollision = BlockCollisionInit(ME_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void ME_TitleMetal::Update(float _DeltaTime)
{
	if (GetLiveTime() > 1.0f&& true==StateChangeBool)
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::SlantBoard);
		StateChangeBool = false;
	}
}

void ME_TitleMetal::Render(float _Delta)
{

};


