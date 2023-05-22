#include "PrecompileHeader.h"
#include "ClockPaddle3.h"

//PlatForm
//Core

//Actor
#include "ClockUnderBar.h"


ClockPaddle3::ClockPaddle3()
{
}

ClockPaddle3::~ClockPaddle3()
{
}

void ClockPaddle3::Start()
{
	ClockPaddle3s = Init(ClockPaddle3s, "CodePaddle03.png", { 90,90 }, { 80,120 });
	ClockPaddle3sCollision = CollisionInit(ClockPaddle3sCollision, { 90,90 }, { 80,120 });
}

void ClockPaddle3::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle3sCollision))
	{
		ClockUnderBar::CM->ClockPasswordPush(3);
	}
}

void ClockPaddle3::Render(float _Delta)
{

};
