#include "PrecompileHeader.h"
#include "ClockPanel.h"

//PlatForm
//Core




ClockPanel::ClockPanel()
{
}

ClockPanel::~ClockPanel()
{
}

void ClockPanel::Start()
{
	//BoxCroix,UnderBar,Paddle Create
	//Scale조정하기
	Init(ClockPanels, "Panel04.png", { 96,96 }, float4::Zero);
}

void ClockPanel::Update(float _DeltaTime)
{

}

void ClockPanel::Render(float _Delta)
{

};
