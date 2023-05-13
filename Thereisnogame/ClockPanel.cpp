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
	ClockPanels=Init(ClockPanels, "Panel04 #75255.png", { 629,373 }, float4::Zero);
	ClockPanels->GetTransform()->SetLocalRotation({ 0,0,90 });
}

void ClockPanel::Update(float _DeltaTime)
{

}

void ClockPanel::Render(float _Delta)
{

};
