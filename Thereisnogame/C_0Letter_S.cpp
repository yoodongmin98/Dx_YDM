#include "PrecompileHeader.h"
#include "C_0Letter_S.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_S::C_Letter_S()
{
}

C_Letter_S::~C_Letter_S()
{
}

void C_Letter_S::Start()
{
	Init(Letter_S, "Letter07.png", { 103,436,1 }, { 200,690,-10 });
}

void C_Letter_S::Update(float _DeltaTime)
{
	Repeat(5, _DeltaTime * 0.7f);
}

void C_Letter_S::Render(float _Delta)
{

};
