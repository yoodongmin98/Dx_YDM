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
	Panel_Continues=Init(Panel_Continues, "Menu_Panel_Continue.png", { 306,195,1 }, { 0,-615,0 });
	Panel_ContinuesCollision = CollisionInit(Panel_ContinuesCollision, { 306,195,1 }, { 0,-615,0 });
	Font = FontCreate(Font, 30, "레벨 선택", { 0,-545,0 }, GetTransform(), 1);
}

void Panel_Continue::Update(float _DeltaTime)
{

}

void Panel_Continue::Render(float _Delta)
{

};

void Panel_Continue::ZRotations(float _DeltaTime)
{
	GetTransform()->SetLocalRotation(float4::LerpClamp(GetTransform()->GetLocalRotation(), float4::Zero, _DeltaTime));
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), {0,305,0}, _DeltaTime));
}

void Panel_Continue::RZRotations(float _DeltaTime)
{
	GetTransform()->SetLocalRotation(float4::LerpClamp(GetTransform()->GetLocalRotation(), { 0,0,-90.0f }, _DeltaTime));
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-615,0 }, _DeltaTime*1.5f));
}
