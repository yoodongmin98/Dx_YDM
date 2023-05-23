#include "PrecompileHeader.h"
#include "ClockDayandNight.h"

//PlatForm
//Core

#include "ColManager.h"


ClockDayandNight::ClockDayandNight()
{
}

ClockDayandNight::~ClockDayandNight()
{
}


bool ClockDayandNightandNightImageLoad = true;
void ClockDayandNight::Start()
{
	if (true == ClockDayandNightandNightImageLoad)
	{
		AnimationImageLoad("ClockDay");
		AnimationImageLoad("ClockNight");
		ClockDayandNightandNightImageLoad = false;
	}
	ClockDay = AnimationInit(ClockDay, "ClockDay00.png", { 385,205 }, {-330,145}, "ClockDayflicker", "ClockDay", 1, 0.7f);
	ClockNight = AnimationInit(ClockNight, "ClockNight00.png", { 385,205 }, { -330,145 }, "ClockNightflicker", "ClockNight", 1, 0.7f);
	
}

void ClockDayandNight::Update(float _DeltaTime)
{
	if (1 == ColManager::MG->GetClockValue())
	{
		ClockDay->Off();
		ClockNight->On();
	}
	else
	{
		ClockDay->On();
		ClockNight->Off();
	}
}

void ClockDayandNight::Render(float _Delta)
{

};
