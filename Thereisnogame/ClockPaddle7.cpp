#include "PrecompileHeader.h"
#include "ClockPaddle7.h"

//PlatForm
//Core




ClockPaddle7::ClockPaddle7()
{
}

ClockPaddle7::~ClockPaddle7()
{
}

void ClockPaddle7::Start()
{
	ClockPaddle7s = Init(ClockPaddle7s, "CodePaddle07.png", { 90,90 }, { -80,-40 });
	ClockPaddle7sCollision = CollisionInit(ClockPaddle7sCollision, { 90,90 }, { -80,-40 });
}

void ClockPaddle7::Update(float _DeltaTime)
{

}

void ClockPaddle7::Render(float _Delta)
{

};
