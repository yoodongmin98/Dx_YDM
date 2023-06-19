#include "PrecompileHeader.h"
#include "BalloonSecure.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Mouse.h"
#include "Play within a play Level.h"
BalloonSecure::BalloonSecure()
{
	
}

BalloonSecure::~BalloonSecure()
{
}

void BalloonSecure::Start()
{
	BalloonSecures = Init(BalloonSecures, "BalloonSecure.png", { 1,1 }, float4::Zero); //323 351
	BalloonSecuresCollision = CollisionInit(BalloonSecuresCollision, { 1,1 }, float4::Zero);
	GetTransform()->SetLocalPosition({ 300,235,0 });
}

void BalloonSecure::Update(float _DeltaTime)
{
	BalloonScaleSet(_DeltaTime);
	BalloonStateDeathCheck();
}

void BalloonSecure::Render(float _Delta)
{

};

void BalloonSecure::BalloonScaleSet(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetIsDeathN()
		&& false == LevelStateManager::MG->GetIsBalloonUp())
	{
		On();
		if (BalloonXscale <= 323.0f)
		{
			BalloonXscale += 323.0f* _DeltaTime*0.6f;
		}
		if (BalloonYscale <= 351.0f)
		{
			BalloonYscale += 351.0f* _DeltaTime*0.6f;
			GetTransform()->AddLocalPosition({ 0,175.0f * _DeltaTime*0.6f,0 });
		}
		BalloonSecures->GetTransform()->SetLocalScale({ BalloonXscale ,BalloonYscale });
		BalloonSecuresCollision->GetTransform()->SetLocalScale({ BalloonXscale ,BalloonYscale });
	}
}

void BalloonSecure::BalloonStateDeathCheck()
{
	if (BalloonSecuresCollision->Collision(ActorTypeEnum::Cursor, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::PopsBalloon);
		LevelStateManager::MG->SetIsPopBalloonTrue();
		Death();
	}
}

