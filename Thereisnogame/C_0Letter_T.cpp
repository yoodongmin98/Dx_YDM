#include "PrecompileHeader.h"
#include "C_0Letter_T.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_T::C_Letter_T()
{
}

C_Letter_T::~C_Letter_T()
{
}

void C_Letter_T::Start()
{

	Init(Letter_T, "Letter01.png", { 140,458,1 }, { -180,720,0 });
}

void C_Letter_T::Update(float _DeltaTime)
{
	Repeat(5, _DeltaTime*0.7f);
}

void C_Letter_T::Render(float _Delta)
{

};
