#include "PrecompileHeader.h"
#include "ClockPaddle3.h"

//PlatForm
//Core




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

}

void ClockPaddle3::Render(float _Delta)
{

};
