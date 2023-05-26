#include "PrecompileHeader.h"
#include "F_Korea.h"

F_Korea::F_Korea()
{
}

F_Korea::~F_Korea()
{
}

void F_Korea::Start()
{
	Init(F_Koreas, "Flag_Korea.png", { 198,727,1 }, { 330,700,0 });//400
	F_KoreasCollision = CollisionInit(F_KoreasCollision, { 198,727,1 }, { 330,700,0 });
}

void F_Korea::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.7f);
}

void F_Korea::Render(float _Delta)
{

};
