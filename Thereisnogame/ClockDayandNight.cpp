#include "PrecompileHeader.h"
#include "ClockDayandNight.h"

//PlatForm
//Core




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
	//ClockNight;
}

void ClockDayandNight::Update(float _DeltaTime)
{
	
}

void ClockDayandNight::Render(float _Delta)
{

};
