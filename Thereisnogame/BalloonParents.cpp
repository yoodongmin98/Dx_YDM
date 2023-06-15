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
	BalloonParentss = Init(BalloonParentss, "BalloonSecure.png", { 10.0f,10.0f }, float4::Zero);
	GetTransform()->SetLocalPosition({ 200,300 });
}

void BalloonParents::Update(float _DeltaTime)
{

}

void BalloonParents::Render(float _Delta)
{

};



