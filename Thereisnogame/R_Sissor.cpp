#include "PrecompileHeader.h"
#include "R_Sissor.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"

R_Sissor::R_Sissor()
{
}

R_Sissor::~R_Sissor()
{
}

void R_Sissor::Start()
{
	float4 Position = { -250,-365,0 };
	R_Sissors = Init(R_Sissors, "Icon_Shifumi_Scissor.png", { 232,350 }, Position);
	R_SissorsCollision = CollisionInit(R_SissorsCollision, { 232,350 }, Position);
	GetTransform()->SetLocalPosition({ 0,-175,0 });
}

void R_Sissor::Update(float _DeltaTime)
{
	RoShamboStateCheck(R_SissorsCollision);
	StateClickCheck();
	if (true == IsPos && false == R_SissorClick)
	{
		InfinityShape(_DeltaTime);
	}
}

void R_Sissor::Render(float _Delta)
{

};

void R_Sissor::Up()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 5.0f)
	{
		IsPos = true;
	}
}

void R_Sissor::StateClickCheck()
{
	//Up
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (true == ClickCheck(R_SissorsCollision))
	{
		R_SissorClick = true;
		LevelStateManager::MG->SetIsSelectCardTrue();
		LevelStateManager::MG->SetIsSissorTrue();
		PlaywithinaplayLevel::LM->RSBChangeState(RoshamboState::EnemyCard);
	}
	if (true == LevelStateManager::MG->GetIsSelectCard()
		&& true == R_SissorBool
		&& true == R_SissorClick)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
		if (GetTransform()->GetLocalPosition().y > 120.0f)
		{
			R_SissorBool = false;
		}
	}
}