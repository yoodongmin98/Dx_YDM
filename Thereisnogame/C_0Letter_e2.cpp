#include "PrecompileHeader.h"
#include "C_0Letter_e2.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_e2::C_Letter_e2()
{
}

C_Letter_e2::~C_Letter_e2()
{
}

void C_Letter_e2::Start()
{
	Init(Letter_e2, "Letter13.png", { 110,425,1 }, { 250,500,-10 });
}

void C_Letter_e2::Update(float _DeltaTime)
{
	Repeat(8, _DeltaTime * 0.5f);
	Down(-300.0f, _DeltaTime);
}

void C_Letter_e2::Render(float _Delta)
{

};
