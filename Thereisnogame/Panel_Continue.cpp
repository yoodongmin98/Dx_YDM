#include "PrecompileHeader.h"
#include "Panel_Continue.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

Panel_Continue::Panel_Continue()
{
}

Panel_Continue::~Panel_Continue()
{
}

void Panel_Continue::Start()
{
	GetTransform()->SetLocalRotation({ 0,0,-90 });
	Init(Panel_Continues, "Menu_Panel_Continue.png", { 306,195,1 }, { 700,315,-50 });
}

void Panel_Continue::Update(float _DeltaTime)
{
	if (GameEngineInput::IsPress("PanelTestkey"))
	{
		ZRotations(90,_DeltaTime);
	}
	if (GameEngineInput::IsPress("PanelTestkey2"))
	{
		RZRotations(90, _DeltaTime);
	}
}

void Panel_Continue::Render(float _Delta)
{

};

void Panel_Continue::ZRotations(float RotationValue,float _DeltaTime)
{
	GetTransform()->SetLocalRotation(float4::LerpClamp(GetTransform()->GetLocalRotation(), float4::Zero, _DeltaTime));
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), {-700,-630,0}, _DeltaTime));
}

void Panel_Continue::RZRotations(float RotationValue, float _DeltaTime)
{
	GetTransform()->SetLocalRotation(float4::LerpClamp(GetTransform()->GetLocalRotation(), { 0,0,-RotationValue }, _DeltaTime));
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), float4::Zero, _DeltaTime*1.5));
}
