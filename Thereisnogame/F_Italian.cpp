#include "PrecompileHeader.h"
#include "F_Italian.h"

F_Italian::F_Italian()
{
}

F_Italian::~F_Italian()
{
}

void F_Italian::Start()
{
	Init(F_Italians, "Flag_Italian.png", { 198,727,1 }, { 420,750,0 });//170
	F_ItaliansCollision = CollisionInit(F_ItaliansCollision, { 198,133,1 }, { 420,550,0 });
}

void F_Italian::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.9f);
}

void F_Italian::Render(float _Delta)
{

};
