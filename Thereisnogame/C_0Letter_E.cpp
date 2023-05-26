#include "PrecompileHeader.h"
#include "C_0Letter_E.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_E::C_Letter_E()
{
}

C_Letter_E::~C_Letter_E()
{
}

void C_Letter_E::Start()
{
	Init(Letter_E, "Letter03.png", { 134,458,1 }, { -40,710,0 });
}

void C_Letter_E::Update(float _DeltaTime)
{
	Repeat(7, _DeltaTime * 0.6f);;
}

void C_Letter_E::Render(float _Delta)
{

};
