#include "PrecompileHeader.h"
#include "Arrow3.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

Arrow3::Arrow3()
{
}

Arrow3::~Arrow3()
{
}

void Arrow3::Start()
{

	Arrow_LightOn = CreateComponent<GameEngineSpriteRenderer>();
	Arrow_LightOn->SetTexture("ArrowLightOn.png");
	Arrow_LightOn->GetTransform()->SetLocalScale({ 241,129,1 });
	Arrow_LightOn->GetTransform()->SetLocalPosition({ 512,-522,-10 });
	Arrow_LightOn->GetTransform()->SetLocalRotation({ 0, 0, -150 });
	Arrow_LightOn->Off();

	Arrow_LightOff = CreateComponent<GameEngineSpriteRenderer>();
	Arrow_LightOff->SetTexture("ArrowLightOff.png");
	Arrow_LightOff->GetTransform()->SetLocalScale({ 188,73,1 });
	Arrow_LightOff->GetTransform()->SetLocalPosition({ 505,-520,-10 });
	Arrow_LightOff->GetTransform()->SetLocalRotation({ 0, 0, -150 });
	Arrow_LightOff->On();
}
void Arrow3::Update(float _DeltaTime)
{
	ArrowBlinkTime += _DeltaTime;
	if (ArrowBlinkTime > 1.5f)
	{
		Arrow_LightOn->On();
		Arrow_LightOff->Off();
	}
	if (ArrowBlinkTime > 2.0f)
	{
		Arrow_LightOn->Off();
		Arrow_LightOff->On();
		ArrowBlinkTime = 0.0f;
	}
}

void Arrow3::Render(float _Delta)
{

};
