#include "PrecompileHeader.h"
#include "F_Spanish.h"
#include "ActorTypeEnum.h"

F_Spanish::F_Spanish()
{
}

F_Spanish::~F_Spanish()
{
}

void F_Spanish::Start()
{
	Init(F_Spanishs, "Flag_Spanish.png", { 198,727,1 }, { -310,750,0 });//400
	F_SpanishsCollision = CollisionInit(F_SpanishsCollision, { 198,133,1 }, { -310,550,0 });
	Font = FontCreate(Font, 20, "iNo hay espanol disponible!", { 0,-260,0 }, GetTransform(), 2);
	Font->Off();
}

void F_Spanish::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.5f);
	if (F_SpanishsCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Font->On();
	}
	else
	{
		Font->Off();
	}
}

void F_Spanish::Render(float _Delta)
{

};
