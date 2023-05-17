#include "PrecompileHeader.h"
#include "Cup.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineCollision.h>


Cup::Cup()
{
}

Cup::~Cup()
{
}

void Cup::Start()
{
	//Render2°³
	float4 Position = { 300,0,0 };
	Cups = Init(Cups, "CupObj_Empty.png", { 94,121 }, Position);
	Cups_Overlap = Init(Cups_Overlap, "CupObj_Empty_Overlap.png", { 126,153 }, { Position.x - 3,Position.y + 3 });
	CupCollision = CollisionInit(CupCollision, { 50,50,1 }, Position);

	Cups_Overlap->On();
	Cups->Off();
}

void Cup::Update(float _DeltaTime)
{
	Fall(Cups, Cups_Overlap, CupCollision,60.5f,_DeltaTime);
	CatchCheck(Cups, Cups_Overlap, CupCollision);
}

void Cup::Render(float _Delta)
{

};
