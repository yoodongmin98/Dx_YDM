#include "PrecompileHeader.h"
#include "C_0Letter_H .h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_H::C_Letter_H()
{
}

C_Letter_H::~C_Letter_H()
{
}

void C_Letter_H::Start()
{
	Init(Letter_H, "Letter02.png", { 125,459,1 }, { -100,600,-10 });
}

void C_Letter_H::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.8f);
}

void C_Letter_H::Render(float _Delta)
{

};
