#include "PrecompileHeader.h"
#include "ClockPaddle4.h"

//PlatForm
//Core




ClockPaddle4::ClockPaddle4()
{
}

ClockPaddle4::~ClockPaddle4()
{
}

void ClockPaddle4::Start()
{
	ClockPaddle4s = Init(ClockPaddle4s, "CodePaddle04.png", { 90,90 }, { -80,40 });
	ClockPaddle4sCollision = CollisionInit(ClockPaddle4sCollision, { 90,90 }, { -80,40 });
}

void ClockPaddle4::Update(float _DeltaTime)
{

}

void ClockPaddle4::Render(float _Delta)
{

};
