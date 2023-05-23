#include "PrecompileHeader.h"
#include "Cup_Full.h"

//PlatForm
//Core


//Actor
#include "Mouse.h"


Cup_Full::Cup_Full()
{
}

Cup_Full::~Cup_Full()
{
}

void Cup_Full::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	Cup_Fulls = Init(Cup_Fulls, "CupObj_Full.png", { 94,121 }, Position);
	Cup_Fulls_overlap = Init(Cup_Fulls_overlap, "CupObj_Full_Overlap.png", { 126,153 }, { Position.x - 3,Position.y + 3 });
	Cup_FullsCollision = CollisionInit(Cup_FullsCollision, { 94,121,1 }, Position);
}

void Cup_Full::Update(float _DeltaTime)
{
	Fall(Cup_Fulls, Cup_Fulls_overlap, Cup_FullsCollision, 60.5f, _DeltaTime);
	CatchCheck(Cup_Fulls, Cup_Fulls_overlap, Cup_FullsCollision);
}

void Cup_Full::Render(float _Delta)
{

};
