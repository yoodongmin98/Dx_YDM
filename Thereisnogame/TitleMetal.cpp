#include "PrecompileHeader.h"
#include "TitleMetal.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"



TitleMetal::TitleMetal()
{
	
}

TitleMetal::~TitleMetal()
{
}

void TitleMetal::Start()
{
	float4 Position = float4::Zero;
	TitleMetals = Init(TitleMetals, "TitleMetal_T.png", { 94,142 }, Position);
	TitleMetals_overlap = Init(TitleMetals_overlap, "TitleMetal_T_Overlap.png", { 123,171 }, { Position.x - 3,Position.y + 3 });
	TitleMetalsCollision = CollisionInit(TitleMetalsCollision, { 123,171 }, Position);
}

bool CreateMetalBoolss = true;
void TitleMetal::Update(float _DeltaTime)
{
	if (true == CreateMetalBoolss)
	{
		TitleMetals->GetTransform()->SetLocalPosition(CreatePosition);
		TitleMetals_overlap->GetTransform()->SetLocalPosition(CreatePosition);
		TitleMetalsCollision->GetTransform()->SetLocalPosition(CreatePosition);
		CreateMetalBoolss = false;
	}
	Fall(TitleMetals, TitleMetals_overlap, TitleMetalsCollision,71.0f, _DeltaTime);
	CatchCheck(TitleMetals, TitleMetals_overlap, TitleMetalsCollision);
}

void TitleMetal::Render(float _Delta)
{

};


