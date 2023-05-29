#include "PrecompileHeader.h"
#include "Cordon.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
Cordon::Cordon()
{
}

Cordon::~Cordon()
{
}

void Cordon::Start()
{
	BackCurtainPtr = GetLevel()->CreateActor<BackCurtain>();
	Cordons = Init(Cordons, "Cordon.png", { 119,693,1 }, { 400,700,0 });
	CordonsCollision = CollisionInit(CordonsCollision, { 119,693,1 }, { 400,700,0 });
	CordonsCollision->Off();
}

void Cordon::Update(float _DeltaTime)
{
	if (GetLiveTime() > 5.0f && true == MoveValue)
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
		GetLevel()->CreateActor<AlphaCircle>();
	}
	CordonCollisionCheck(_DeltaTime);
}

void Cordon::Render(float _Delta)
{

};

void Cordon::CordonCollisionCheck(float _DeltaTime)
{
	if (true == CordonsCollision->IsDeath())
	{
		std::function<void()> CordonFunctional;
		CordonFunctional = std::bind(&BackCurtain::CurtainOpen, BackCurtainPtr.get());
		CordonFunctional();
		GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,Values }, _DeltaTime * 0.5f));
	}
}