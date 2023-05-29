#include "PrecompileHeader.h"
#include "Plaque.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "BackCurtain.h"
#include "Play within a play Level.h"

Plaque::Plaque()
{
}

Plaque::~Plaque()
{
}

void Plaque::Start()
{
	Plaques = Init(Plaques, "Plaque.png", { 446,245 }, { 5,50,0 });
	PlaquesCollision = CollisionInit(PlaquesCollision, { 400,200 }, { 5,50,0 });
	PlaquesCollision->Off();
}

void Plaque::Update(float _DeltaTime)
{
	if (true == ClickCheck(PlaquesCollision) && Chap1LevelState::ClickCordon==PlaywithinaplayLevel::LM->GetLevelState())
	{
		PlaquesCollision->On();
		ClickCount++;
	}
	if (ClickCount > 5)
	{
		int a = 0;
	}
}

void Plaque::Render(float _Delta)
{

};


