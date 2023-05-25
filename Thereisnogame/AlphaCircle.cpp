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
	AlphaCircles = Init(AlphaCircles, "IndiaTitleVignette.png", { 1281.0f, 720.0f , 1.0f }, { 0,0,0 });
	AlphaCircles->ColorOptionValue.MulColor.a = 0.3;
	
}
void AlphaCircle::Update(float _DeltaTime)
{
	
}