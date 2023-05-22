#include "PrecompileHeader.h"
#include "ClockPaddle5.h"

//PlatForm
//Core


//Actor
#include "ClockUnderBar.h"

ClockPaddle5::ClockPaddle5()
{
}

ClockPaddle5::~ClockPaddle5()
{
}

void ClockPaddle5::Start()
{
	ClockPaddle5s = Init(ClockPaddle5s, "CodePaddle05.png", { 90,90 }, { 0,40 });
	ClockPaddle5sCollision = CollisionInit(ClockPaddle5sCollision, { 90,90 }, { 0,40 });
}

void ClockPaddle5::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle5sCollision))
	{
		ClockUnderBar::CM->ClockPasswordPush(5);
	}
}

void ClockPaddle5::Render(float _Delta)
{

};
