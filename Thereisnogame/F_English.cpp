#include "PrecompileHeader.h"
#include "F_English.h"
#include "ActorTypeEnum.h"

F_English::F_English()
{
}

F_English::~F_English()
{
}

void F_English::Start()
{
	Init(F_Englishs, "Flag_English.png", { 198,727,1 }, { -70,750,0 });//320
	F_EnglishsCollision = CollisionInit(F_EnglishsCollision, { 198,133,1 }, { -70,550,0 });
	Font = FontCreate(Font, 20, "Don't apply in English!", { 0,-260,0 }, GetTransform(), 2);
	Font->Off();
}

void F_English::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.6f);
	if (F_EnglishsCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Font->On();
	}
	else
	{
		Font->Off();
	}
}

void F_English::Render(float _Delta)
{

};
