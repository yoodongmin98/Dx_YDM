#include "PrecompileHeader.h"
#include "C_0Letter_O.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_O::C_Letter_O()
{
}

C_Letter_O::~C_Letter_O()
{
}

void C_Letter_O::Start()
{
	Init(Letter_O, "Letter09.png", { 124,468,1 }, { -70,500,0 });
}

void C_Letter_O::Update(float _DeltaTime)
{
	Repeat(7, _DeltaTime * 0.8f);
}

void C_Letter_O::Render(float _Delta)
{

};
