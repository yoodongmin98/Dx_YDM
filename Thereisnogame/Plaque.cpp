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
	if (Chap1LevelState::ClickCordon == PlaywithinaplayLevel::LM->GetLevelState())
	{
		PlaquesCollision->On();
		if (true == ClickCheck(PlaquesCollision))
		{
			ClickCount++;
		}
	}
	else
	{
		PlaquesCollision->Off();
	}
	if (ClickCount > 5)
	{
		//юс╫ц
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::CreateBoard);
	}
}

void Plaque::Render(float _Delta)
{

};


