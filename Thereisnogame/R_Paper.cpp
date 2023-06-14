#include "PrecompileHeader.h"
#include "R_Paper.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"

R_Paper::R_Paper()
{
}

R_Paper::~R_Paper()
{
}

void R_Paper::Start()
{
	float4 Position = { -350,-365,0 };
	R_Papers = Init(R_Papers, "Icon_Shifumi_Paper.png", { 232,350 }, Position);
	R_PapersCollision = CollisionInit(R_PapersCollision, { 116,350 }, Position + float4::Right * 58);
	GetTransform()->SetLocalPosition({ 0,-175,0 });
}

void R_Paper::Update(float _DeltaTime)
{
	RoShamboStateCheck(R_PapersCollision);
	StateClickCheck();
	if (true == IsPos && false == R_PaperClick)
	{
		InfinityShape(_DeltaTime);
	}
}

void R_Paper::Render(float _Delta)
{

};

void R_Paper::Up()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 0.0f)
	{
		IsPos = true;
	}
}

void R_Paper::StateClickCheck()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	//Up
	if (true == ClickCheck(R_PapersCollision))
	{
		R_PaperClick = true;
		LevelStateManager::MG->SetIsSelectCardTrue();
		LevelStateManager::MG->SetIsPaperTrue();
		PlaywithinaplayLevel::LM->RSBChangeState(RoshamboState::EnemyCard);
	}
	if (true == LevelStateManager::MG->GetIsSelectCard()
		&& true==R_PaperBool
		&& true == R_PaperClick)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
		if (GetTransform()->GetLocalPosition().y > 120.0f)
		{
			R_PaperBool = false;
		}
	}
}
