#include "PrecompileHeader.h"
#include "C_0Letter_A.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_A::C_Letter_A()
{
}

C_Letter_A::~C_Letter_A()
{
}

void C_Letter_A::Start()
{
	Init(Letter_A, "Letter11.png", { 124,468,1 }, { 90,500,-10 });
}

void C_Letter_A::Update(float _DeltaTime)
{
	Repeat(3, _DeltaTime * 0.4f);
	Down(-300.0f, _DeltaTime);
}

void C_Letter_A::Render(float _Delta)
{

};
