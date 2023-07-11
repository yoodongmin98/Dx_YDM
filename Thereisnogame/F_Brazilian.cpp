#include "PrecompileHeader.h"
#include "F_Brazilian.h"
#include "ActorTypeEnum.h"

F_Brazilian::F_Brazilian()
{
}

F_Brazilian::~F_Brazilian()
{
}

void F_Brazilian::Start()
{
	Init(F_Brazilians, "Flag_Brazilian.png", { 198,727,1 }, {-170,750,0});
	F_BraziliansCollision = CollisionInit(F_BraziliansCollision, { 198,133,1 }, { -170,550,0 });
	Font = FontCreate(Font, 20, "Nao podem candidatar-se no Brasil", { 0,-260,0 }, GetTransform(), 2);
	Font->Off();
}

void F_Brazilian::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.4f);
	if (F_BraziliansCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Font->On();
	}
	else
	{
		Font->Off();
	}
}

void F_Brazilian::Render(float _Delta)
{

};
