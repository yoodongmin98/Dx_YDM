#include "PrecompileHeader.h"
#include "F_English.h"

F_English::F_English()
{
}

F_English::~F_English()
{
}

void F_English::Start()
{
	Init(F_Englishs, "Flag_English.png", { 198,727,1 }, { -70,700,0 });//320
	F_EnglishsCollision = CollisionInit(F_EnglishsCollision, { 198,727,1 }, { -70,700,0 });
}

void F_English::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.6f);
}

void F_English::Render(float _Delta)
{

};
