#include "PrecompileHeader.h"
#include "ClockPaddle8.h"

//PlatForm
//Core




ClockPaddle8::ClockPaddle8()
{
}

ClockPaddle8::~ClockPaddle8()
{
}

void ClockPaddle8::Start()
{
	ClockPaddle8s = Init(ClockPaddle8s, "CodePaddle08.png", { 90,90 }, { 0,-40 });
	ClockPaddle8sCollision = CollisionInit(ClockPaddle8sCollision, { 90,90 }, { 0,-40 });
}

void ClockPaddle8::Update(float _DeltaTime)
{

}

void ClockPaddle8::Render(float _Delta)
{

};
