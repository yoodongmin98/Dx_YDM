#include "PrecompileHeader.h"
#include "F_Russian.h"

F_Russian::F_Russian()
{
}

F_Russian::~F_Russian()
{
}

void F_Russian::Start()
{
	Init(F_Russians, "Flag_Russian.png", { 198,727,1 }, { -400,700,0 });//200
}

void F_Russian::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.6f);
}

void F_Russian::Render(float _Delta)
{

};
