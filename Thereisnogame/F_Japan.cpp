#include "PrecompileHeader.h"
#include "F_Japan.h"

F_Japan::F_Japan()
{
}

F_Japan::~F_Japan()
{
}

void F_Japan::Start()
{
	Init(F_Japans, "Flag_Japan.png", { 198,727,1 }, { -340,700,0 });//-30
}

void F_Japan::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.8f);
}

void F_Japan::Render(float _Delta)
{

};
