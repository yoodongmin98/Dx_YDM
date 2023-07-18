#include "PrecompileHeader.h"
#include "StartButton.h"
//Base
//PlatForm
//Core
//Actor
StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}

void StartButton::Start()
{
	StartButtons = Init(StartButtons, "End_BoutonPlay_Closed.png", { 144,131 }, float4::Zero);
	Font = FontCreate(Font, 25, "PLAY", float4::Up * 120, GetTransform(), 1);
}

void StartButton::Update(float _DeltaTime)
{

}

void StartButton::Render(float _Delta)
{

};

