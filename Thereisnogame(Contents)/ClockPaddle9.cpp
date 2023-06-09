#include "PrecompileHeader.h"
#include "ClockPaddle9.h"

//PlatForm
//Core

//Actor
#include "ClockUnderBar.h"

ClockPaddle9::ClockPaddle9()
{
}

ClockPaddle9::~ClockPaddle9()
{
}

void ClockPaddle9::Start()
{
	ClockPaddle9s = Init(ClockPaddle9s, "CodePaddle09.png", { 90,90 }, {80,-40});
	ClockPaddle9sCollision = CollisionInit(ClockPaddle9sCollision, { 70,70 }, { 80,-40 });
}

void ClockPaddle9::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle9sCollision))
	{
		ClockUnderBar::CM->ClockPasswordPush(9);
	}
}

void ClockPaddle9::Render(float _Delta)
{

};
