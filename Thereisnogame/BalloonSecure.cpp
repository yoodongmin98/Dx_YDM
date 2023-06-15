#include "PrecompileHeader.h"
#include "BalloonSecure.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
BalloonSecure::BalloonSecure()
{
	
}

BalloonSecure::~BalloonSecure()
{
}

void BalloonSecure::Start()
{
	BalloonSecures = Init(BalloonSecures, "BalloonSecure.png", { 1,1 }, float4::Zero); //323 351
	GetTransform()->SetLocalPosition({ 300,235,0 });
}

void BalloonSecure::Update(float _DeltaTime)
{
	BalloonScaleSet();
}

void BalloonSecure::Render(float _Delta)
{

};

void BalloonSecure::BalloonScaleSet()
{
	if (true == LevelStateManager::MG->GetIsDeathN()
		&& false == LevelStateManager::MG->GetIsBalloonUp())
	{
		On();
		if (BalloonXscale <= 323.0f)
		{
			BalloonXscale += 0.323f;
		}
		if (BalloonYscale <= 351.0f)
		{
			BalloonYscale += 0.351f;
			GetTransform()->AddLocalPosition({ 0,0.175f,0 });
		}
		BalloonSecures->GetTransform()->SetLocalScale({ BalloonXscale ,BalloonYscale });
	}
}

