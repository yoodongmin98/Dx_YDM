#include "PrecompileHeader.h"
#include "ClockUnderBar.h"

//PlatForm
//Core




ClockUnderBar::ClockUnderBar()
{
}

ClockUnderBar::~ClockUnderBar()
{
}

void ClockUnderBar::Start()
{
	ClockUnderBars = Init(ClockUnderBars, "Chap04_MapBranchHorizontal.png", { 18,4 }, float4::Zero);
}

void ClockUnderBar::Update(float _DeltaTime)
{

}

void ClockUnderBar::Render(float _Delta)
{

};
