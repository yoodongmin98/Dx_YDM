#include "PrecompileHeader.h"
#include "BalloonSecure.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor

BalloonSecure::BalloonSecure()
{
	
}

BalloonSecure::~BalloonSecure()
{
}

void BalloonSecure::Start()
{
	BalloonSecures = Init(BalloonSecures, "BalloonSecure.png", { 323,351 }, float4::Zero);
	GetTransform()->SetLocalPosition({ 300,410,0 });
}

void BalloonSecure::Update(float _DeltaTime)
{
	
}

void BalloonSecure::Render(float _Delta)
{

};

