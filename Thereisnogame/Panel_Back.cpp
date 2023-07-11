#include "PrecompileHeader.h"
#include "Panel_Back.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include "MainMenuLevel.h"
Panel_Back::Panel_Back()
{
}

Panel_Back::~Panel_Back()
{
}

void Panel_Back::Start()
{
	Init(Panel_Backs, "MenuOptions_BackPanel.png", { 228,195,1 }, { -300,-750,0 });
	Panel_BacksCollision = CollisionInit(Panel_BacksCollision, { 150,100,1 }, { -290,-780,0 });
	Font = FontCreate(Font, 25, "µÚ·Î", { -280,-760,0 }, GetTransform(), 1);
}

void Panel_Back::Update(float _DeltaTime)
{
	if (true == ClickCheck(Panel_BacksCollision))
	{
		Play(Sound, "MainMenu_Click.wav", 0.1f);
		MainMenuLevel::ML->SetIsClickBackPanelTrue();
	}
}

void Panel_Back::Render(float _Delta)
{

};

void Panel_Back::ZRotations(float _DeltaTime)
{
	GetTransform()->SetLocalRotation(float4::LerpClamp(GetTransform()->GetLocalRotation(), float4::Zero, _DeltaTime));
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { -230,900,0 }, _DeltaTime));
}

void Panel_Back::RZRotations(float _DeltaTime)
{
	GetTransform()->SetLocalRotation(float4::LerpClamp(GetTransform()->GetLocalRotation(), { 0,0,-90.0f }, _DeltaTime));
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), float4::Zero, _DeltaTime * 1.5f));
}
