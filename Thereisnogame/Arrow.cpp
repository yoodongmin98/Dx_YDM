#include "PrecompileHeader.h"
#include "Arrow.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

Arrow::Arrow()
{
}

Arrow::~Arrow()
{
}

void Arrow::Start()
{
	Init(Arrow_LightOn, "ArrowLightOn.png", { 241,129,1 }, { 250,40,-10 });
	Init(Arrow_LightOff, "ArrowLightOff.png", { 188,73,1 }, { 250,0,-10 });
	GetTransform()->AddLocalRotation({ 0,0,-50 });
}
void Arrow::Update(float _DeltaTime)
{
	ArrowTestTime += _DeltaTime;
	/*if (ArrowTestTime > 1.0f)
	{
		Arrow_LightOff->Off();
		Arrow_LightOn->On();
	}
	if (ArrowTestTime > 2.0f)
	{
		Arrow_LightOff->On();
		Arrow_LightOn->Off();
		ArrowTestTime = 0.0f;
	}*/
	
}

void Arrow::Render(float _Delta)
{

};
