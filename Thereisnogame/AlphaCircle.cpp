#include "PrecompileHeader.h"
#include "AlphaCircle.h"

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
	AlphaCircles = CreateComponent<GameEngineSpriteRenderer>();
	AlphaCircles->SetTexture("IndiaTitleVignette.png");
	AlphaCircles->GetTransform()->SetLocalScale({ 1281.0f, 720.0f , 1.0f });
	

}
void AlphaCircle::Update(float _DeltaTime)
{


}