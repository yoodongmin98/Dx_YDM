#include "PrecompileHeader.h"
#include "C_0Letter_N.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_N::C_Letter_N()
{
}

C_Letter_N::~C_Letter_N()
{
}

void C_Letter_N::Start()
{
	Init(Letter_N, "Letter08.png", { 161,464,1 }, { -170,490,0 });
}

void C_Letter_N::Update(float _DeltaTime)
{
	Repeat(4, _DeltaTime * 0.6f);
}

void C_Letter_N::Render(float _Delta)
{

};
