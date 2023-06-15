#include "PrecompileHeader.h"
#include "BalloonParents.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
BalloonParents::BalloonParents()
{

}

BalloonParents::~BalloonParents()
{
}

void BalloonParents::Start()
{
	BalloonParentss = Init(BalloonParentss, "BalloonSecure.png", { 1.0f,1.0f }, float4::Zero);
	BalloonParentss->Off();
	GetTransform()->SetLocalPosition({ 310,210 });
}

bool ShakeBalloonBool = true;

void BalloonParents::Update(float _DeltaTime)
{
	if(true == ShakeBalloonBool)
	{
		GetTransform()->AddLocalRotation({ 0,0,0.01f });
	}
	if (GetTransform()->GetLocalRotation().z >= 15.0f)
	{
		ShakeBalloonBool = false;
	}
	if (false == ShakeBalloonBool)
	{
		GetTransform()->AddLocalRotation({ 0,0,-0.01f });
	}
	if (GetTransform()->GetLocalRotation().z <= -15.0f)
	{
		ShakeBalloonBool = true;
	}
}

void BalloonParents::Render(float _Delta)
{

};



