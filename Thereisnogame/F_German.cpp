#include "PrecompileHeader.h"
#include "F_German.h"

F_German::F_German()
{
}

F_German::~F_German()
{
}

void F_German::Start()
{
	Init(F_Germans, "Flag_German.png", { 198,727,1 }, { 180,700,0 });//220
}

void F_German::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.8f);
}

void F_German::Render(float _Delta)
{

};
