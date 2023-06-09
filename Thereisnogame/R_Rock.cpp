#include "PrecompileHeader.h"
#include "R_Rock.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"

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
	RoShamboStateCheck(R_RocksCollision);
	StateClickCheck();
	if(true== IsPos && false == R_RockClick)
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
		IsPos = true;
	}
}

void R_Rock::StateClickCheck()
{
	//Up
	if (true == ClickCheck(R_RocksCollision))
	{
		R_RockClick = true;
		LevelStateManager::MG->SetIsSelectCardTrue();
		LevelStateManager::MG->SetIsRockTrue();
		PlaywithinaplayLevel::LM->RSBChangeState(RoshamboState::EnemyCard);
	}
	if (true == LevelStateManager::MG->GetIsSelectCard()
		&& true == R_RockBool
		&& true == R_RockClick)
	{
		GetTransform()->AddLocalPosition({ 0,1,0 });
		if (GetTransform()->GetLocalPosition().y > 120.0f)
		{
			R_RockBool = false;
		}
	}
}
