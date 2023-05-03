#include "PrecompileHeader.h"
#include "C_0Letter_G.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_G::C_Letter_G()
{
}

C_Letter_G::~C_Letter_G()
{
}

void C_Letter_G::Start()
{
	Init(Letter_G, "Letter10.png", { 128,440,1 }, { 30,510,-10 });
}

void C_Letter_G::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.7f);
}

void C_Letter_G::Render(float _Delta)
{

};
