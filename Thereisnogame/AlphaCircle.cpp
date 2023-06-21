#include "PrecompileHeader.h"
#include "AlphaCircle.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
#include <GameEnginePlatform/GameEngineImage.h>
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>






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
	

	AlphaCircles->ColorOptionValue.MulColor.a = 0.3f;
	
}
void AlphaCircle::Update(float _DeltaTime)
{
	AlphaCircles->GetTransform()->SetLocalPosition({GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition().x,0,0});
	
}