#include "PrecompileHeader.h"
#include "ClockPaddle2.h"

//PlatForm
//Core

//Actor
#include "ClockUnderBar.h"


ClockPaddle2::ClockPaddle2()
{
}

ClockPaddle2::~ClockPaddle2()
{
}

void ClockPaddle2::Start()
{
	ClockPaddle2s = Init(ClockPaddle2s, "CodePaddle02.png", { 90,90 }, { 0,120 });
	ClockPaddle2sCollision = CollisionInit(ClockPaddle2sCollision, { 70,70 }, { 0,120 });
}

void ClockPaddle2::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockPaddle2sCollision))
	{
		Play(Sound, "Digicode.wav", 0.1f);
		ClockUnderBar::CM->ClockPasswordPush(2);
	}
}

void ClockPaddle2::Render(float _Delta)
{

};
