#include "PrecompileHeader.h"
#include "C_0Letter_R.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_R::C_Letter_R()
{
}

C_Letter_R::~C_Letter_R()
{
}

void C_Letter_R::Start()
{
	Init(Letter_R, "Letter04.png", { 100,446,1 }, { 30,710,0 });
}

void C_Letter_R::Update(float _DeltaTime)
{
	Repeat(5, _DeltaTime * 0.7f);
}

void C_Letter_R::Render(float _Delta)
{

};
