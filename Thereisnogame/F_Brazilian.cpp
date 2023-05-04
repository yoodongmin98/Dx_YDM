#include "PrecompileHeader.h"
#include "F_Brazilian.h"

F_Brazilian::F_Brazilian()
{
}

F_Brazilian::~F_Brazilian()
{
}

void F_Brazilian::Start()
{
	Init(F_Brazilians, "Flag_Brazilian.png", { 198,727,1 }, {-170,700,0});//130
}

void F_Brazilian::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.4f);
}

void F_Brazilian::Render(float _Delta)
{

};
