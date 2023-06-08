#include "PrecompileHeader.h"
#include "R_Rock.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_Rock::R_Rock()
{
}

R_Rock::~R_Rock()
{
}

void R_Rock::Start()
{
	float4 Position = {-480,-365,0};
	R_Rocks = Init(R_Rocks, "Icon_Shifumi_Rock.png", { 232,350 }, Position);
	R_RocksCollision = CollisionInit(R_RocksCollision, { 232,350 }, Position);
	GetTransform()->SetLocalPosition({ 0,-175,0 });
}

void R_Rock::Update(float _DeltaTime)
{
	if(true== IsPos)
	{
		InfinityShape(_DeltaTime); 
	}
}

void R_Rock::Render(float _Delta)
{

};

void R_Rock::Up()
{
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({0,1,0});
	}
	if (GetTransform()->GetLocalPosition().y >= 5.0f)
	{
		float4 Tests = GetTransform()->GetLocalPosition();
		GetTransform()->SetLocalPosition(GetTransform()->GetLocalPosition());
		IsPos = true;
	}
}

