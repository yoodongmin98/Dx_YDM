#include "PrecompileHeader.h"
#include "ClockPaddle0.h"

//PlatForm
//Core

//Actor
#include "ClockUnderBar.h"


ClockPaddle0::ClockPaddle0()
{
}

ClockPaddle0::~ClockPaddle0()
{
}

void ClockPaddle0::Start()
{
	ClockPaddle0s = Init(ClockPaddle0s, "CodePaddle00.png", { 90,90 }, { 0,-120 });
	ClockPaddle0sCollision = CollisionInit(ClockPaddle0sCollision, { 90,90 }, { 0,-120 });
}

void ClockPaddle0::Update(float _DeltaTime)
{
	
}

void ClockPaddle0::Render(float _Delta)
{

};
