#include "PrecompileHeader.h"
#include "F_French.h"

F_French::F_French()
{
}

F_French::~F_French()
{
}

void F_French::Start()
{
	Init(F_Frenchs, "Flag_French_With_Support.png", { 198,727,1 }, { 50,700,0 });//30
}

void F_French::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.7f);
}

void F_French::Render(float _Delta)
{

};
