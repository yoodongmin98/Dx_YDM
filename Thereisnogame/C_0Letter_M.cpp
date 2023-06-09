#include "PrecompileHeader.h"
#include "C_0Letter_M.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_M::C_Letter_M()
{
}

C_Letter_M::~C_Letter_M()
{
}

void C_Letter_M::Start()
{
	Init(Letter_M, "Letter12.png", { 161,459,1 }, { 160,580,0 });
}

void C_Letter_M::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.7f);
}

void C_Letter_M::Render(float _Delta)
{

};
