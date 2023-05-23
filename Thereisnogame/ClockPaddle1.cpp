#include "PrecompileHeader.h"
#include "ClockPaddle1.h"

//PlatForm
//Core

//Actor
#include "ClockUnderBar.h"


ClockPaddle1::ClockPaddle1()
{
}

ClockPaddle1::~ClockPaddle1()
{
}

void ClockPaddle1::Start()
{
	ClockPaddle1s = Init(ClockPaddle1s, "CodePaddle01.png", { 90,90 }, { -80,120 });
	ClockPaddle1sCollision = CollisionInit(ClockPaddle1sCollision, { 70,70 }, { -80,120 });
}

void ClockPaddle1::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle1sCollision))
	{
		ClockUnderBar::CM->ClockPasswordPush(1);
	}
}

void ClockPaddle1::Render(float _Delta)
{

};
