#include "PrecompileHeader.h"
#include "AlphaCircle.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineImage.h>






AlphaCircle::AlphaCircle()
{

}
AlphaCircle::~AlphaCircle()
{

}

void AlphaCircle::Start()
{
	AlphaCircles = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Alpha);
	AlphaCircles->SetScaleToTexture("IndiaTitleVignette.png");
	AlphaCircles->GetTransform()->SetLocalScale({ 1281.0f, 720.0f , 1.0f });
	AlphaCircles->GetTransform()->SetLocalPosition({ 0,0,0 });

	AlphaCircles->ColorOptionValue.MulColor.a = 0.3f;
	
}
void AlphaCircle::Update(float _DeltaTime)
{
	
}