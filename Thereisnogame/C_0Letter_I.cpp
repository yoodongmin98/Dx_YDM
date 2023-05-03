#include "PrecompileHeader.h"
#include "C_0Letter_I.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_I::C_Letter_I()
{
}

C_Letter_I::~C_Letter_I()
{
}

void C_Letter_I::Start()
{
	Init(Letter_I, "Letter06.png", { 88,434,1 }, { 170,610,-10 });
}

void C_Letter_I::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.6f);
}

void C_Letter_I::Render(float _Delta)
{

};
