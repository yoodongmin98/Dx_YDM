#include "PrecompileHeader.h"
#include "C_0Letter_sE.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_sE::C_Letter_sE()
{
}

C_Letter_sE::~C_Letter_sE()
{
}

void C_Letter_sE::Start()
{
	Init(Letter_sE, "Letter05.png", { 115,452,1 }, {  80,620,-10 });
}

void C_Letter_sE::Update(float _DeltaTime)
{
	Repeat(7, _DeltaTime * 0.8f);
}

void C_Letter_sE::Render(float _Delta)
{

};
