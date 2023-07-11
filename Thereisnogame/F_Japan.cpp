#include "PrecompileHeader.h"
#include "F_Japan.h"
#include "ActorTypeEnum.h"

F_Japan::F_Japan()
{
}

F_Japan::~F_Japan()
{
}

void F_Japan::Start()
{
	Init(F_Japans, "Flag_Japan.png", { 198,727,1 }, { -340,750,0 });//-30
	F_JapansCollision = CollisionInit(F_JapansCollision, { 198,133,1 }, { -340,550,0 });
	Font = FontCreate(Font, 20, "日本語できません！", { 0,-260,0 }, GetTransform(), 2);
	Font->Off();
}

void F_Japan::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.8f);
	if (F_JapansCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Font->On();
	}
	else
	{
		Font->Off();
	}
}

void F_Japan::Render(float _Delta)
{

};
