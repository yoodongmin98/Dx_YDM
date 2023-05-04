#include "PrecompileHeader.h"
#include "DrawaPixel.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>


Panel_DrawaPixel::Panel_DrawaPixel()
{
}

Panel_DrawaPixel::~Panel_DrawaPixel()
{
}

void Panel_DrawaPixel::Start()
{
	Init(Panel_CNC, "CNC.png", { 342*0.9,547*0.9,1 }, { 450,900,0 });//y300
	Init(Panel_Book, "M_DrawMeAPixelBook01.png", { 597,807,1 }, { 0,750,0 });//y150
	//Init(Panel_Box, "BoxMenu.png", { 378,523,1 }, { -380,300,0 });
	//얘는 나중에 이미지 찾기
}

void Panel_DrawaPixel::Update(float _DeltaTime)
{

}

void Panel_DrawaPixel::Render(float _Delta)
{

};

void Panel_DrawaPixel::Down(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-600 }, _DeltaTime));
}

void Panel_DrawaPixel::Up(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,600 }, _DeltaTime));
}
