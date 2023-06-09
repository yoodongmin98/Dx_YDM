#include "PrecompileHeader.h"
#include "ClockPaddle7.h"

//PlatForm
//Core


//Actor
#include "ClockUnderBar.h"

ClockPaddle7::ClockPaddle7()
{
}

ClockPaddle7::~ClockPaddle7()
{
}

void ClockPaddle7::Start()
{
	ClockPaddle7s = Init(ClockPaddle7s, "CodePaddle07.png", { 90,90 }, { -80,-40 });
	ClockPaddle7sCollision = CollisionInit(ClockPaddle7sCollision, { 70,70 }, { -80,-40 });
}

void ClockPaddle7::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle7sCollision))
	{
		Play(Sound, "Digicode.wav", 0.1f);
		ClockUnderBar::CM->ClockPasswordPush(7);
	}
}

void ClockPaddle7::Render(float _Delta)
{

};
