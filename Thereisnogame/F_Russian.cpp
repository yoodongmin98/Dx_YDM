#include "PrecompileHeader.h"
#include "F_Russian.h"
#include "ActorTypeEnum.h"

F_Russian::F_Russian()
{
}

F_Russian::~F_Russian()
{
}

void F_Russian::Start()
{
	Init(F_Russians, "Flag_Russian.png", { 198,727,1 }, { -400,750,0 });//200
	F_RussiansCollision = CollisionInit(F_RussiansCollision, { 198,133,1 }, { -400,550,0 });
	Font = FontCreate(Font, 20, "¬¯¬Ö¬Ý¬î¬Ù¬ñ ¬á¬à¬Õ¬Õ¬Ö¬â¬Ø¬Ú¬Ó¬Ñ¬ä¬î ¬â¬å¬ã¬ã¬Ü¬Ú¬Û ¬ñ¬Ù¬í¬Ü!", { 0,-260,0 }, GetTransform(), 2);
	Font->Off();
}

void F_Russian::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.6f);
	if (F_RussiansCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Font->On();
	}
	else
	{
		Font->Off();
	}
}

void F_Russian::Render(float _Delta)
{

};
