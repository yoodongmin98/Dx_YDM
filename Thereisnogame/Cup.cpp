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
	Cups = Init(Cups, "CupObj_Empty.png", { 94,121 }, {300,0,0});
	CupCollision = CollisionInit(CupCollision, { 50,50,1 }, { 300,0,0 });
}

void Cup::Update(float _DeltaTime)
{
	Fall(Cups, CupCollision,60.5f,_DeltaTime);
	CatchCheck(Cups, CupCollision);
}

void Cup::Render(float _Delta)
{

};
