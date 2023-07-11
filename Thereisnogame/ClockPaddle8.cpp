#include "PrecompileHeader.h"
#include "ClockPaddle8.h"

//PlatForm
//Core


//Actor
#include "ClockUnderBar.h"

ClockPaddle8::ClockPaddle8()
{
}

ClockPaddle8::~ClockPaddle8()
{
}

void ClockPaddle8::Start()
{
	ClockPaddle8s = Init(ClockPaddle8s, "CodePaddle08.png", { 90,90 }, { 0,-40 });
	ClockPaddle8sCollision = CollisionInit(ClockPaddle8sCollision, { 70,70 }, { 0,-40 });
}

void ClockPaddle8::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle8sCollision))
	{
		Play(Sound, "Digicode.wav", 0.1f);
		ClockUnderBar::CM->ClockPasswordPush(8);
	}
}

void ClockPaddle8::Render(float _Delta)
{

};
