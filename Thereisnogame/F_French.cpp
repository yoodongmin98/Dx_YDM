#include "PrecompileHeader.h"
#include "F_French.h"
#include "ActorTypeEnum.h"

F_French::F_French()
{
}

F_French::~F_French()
{
}

void F_French::Start()
{
	Init(F_Frenchs, "Flag_French_With_Support.png", { 198,727,1 }, { 50,750,0 });//30
	F_FrenchsCollision = CollisionInit(F_FrenchsCollision, { 198,133,1 }, { 50,550,0 });
	Font = FontCreate(Font, 20, "Je ne peux pas postuler en francais!", { 0,-260,0 }, GetTransform(), 2);
	Font->Off();
}

void F_French::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.7f);
	if (F_FrenchsCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Font->On();
	}
	else
	{
		Font->Off();
	}
}

void F_French::Render(float _Delta)
{

};
