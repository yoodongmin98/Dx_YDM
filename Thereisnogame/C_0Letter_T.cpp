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

//Actor
#include "LevelStateManager.h"

C_Letter_T::C_Letter_T()
{
}

C_Letter_T::~C_Letter_T()
{
}

void C_Letter_T::Start()
{
	Init(Letter_T, "Letter01.png", { 140,458,1 }, { -180,720,0 });
	Font = FontCreate(Font, 30, "시작을 위해 클릭하지 마세요", float4::Down * 150, GetTransform(), 2);
}

void C_Letter_T::Update(float _DeltaTime)
{
	ColorTime += _DeltaTime;
	Repeat(5, _DeltaTime*0.7f);
	if (false == LevelStateManager::MG->GetIsClickMainMenu())
	{
		Font->ColorOptionValue.MulColor.a = sinf(ColorTime*1.5f);
	}
	else
	{
		Font->Off();
	}
}

void C_Letter_T::Render(float _Delta)
{

};
