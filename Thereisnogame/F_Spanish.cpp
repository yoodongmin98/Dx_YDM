#include "PrecompileHeader.h"
#include "F_Spanish.h"

F_Spanish::F_Spanish()
{
}

F_Spanish::~F_Spanish()
{
}

void F_Spanish::Start()
{
	Init(F_Spanishs, "Flag_Spanish.png", { 198,727,1 }, { -310,700,0 });//400
	F_SpanishsCollision = CollisionInit(F_SpanishsCollision, { 198,727,1 }, { -310,700,0 });
}

void F_Spanish::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.5f);
}

void F_Spanish::Render(float _Delta)
{

};
