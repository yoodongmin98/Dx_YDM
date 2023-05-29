#include "PrecompileHeader.h"
#include "Cordon.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
#include "Play within a play Level.h"
Cordon::Cordon()
{
}

Cordon::~Cordon()
{
}

void Cordon::Start()
{
	Cordons = Init(Cordons, "Cordon.png", { 119,693,1 }, { 400,700,0 });
	CordonsCollision = CollisionInit(CordonsCollision, { 119,693,1 }, { 400,700,0 });
	CordonsCollision->Off();
}

void Cordon::Update(float _DeltaTime)
{
	if (GetLiveTime() > 3.0f&& true==MoveValue)
	{
		GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-Values }, _DeltaTime));
		if (GetTransform()->GetLocalPosition().y < -(Values - 5))
		{
			CordonsCollision->On();
			MoveValue = false;
		}
	}
	if (true == ClickCheck(CordonsCollision))
	{
		CordonsCollision->Death();
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::ClickCordon);
	}
	if (true == CordonsCollision->IsDeath())
	{
		GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,Values }, _DeltaTime * 0.5f));
	}
}

void Cordon::Render(float _Delta)
{

};

