#include "PrecompileHeader.h"
#include "ClockPaddle6.h"

//PlatForm
//Core




ClockPaddle6::ClockPaddle6()
{
}

ClockPaddle6::~ClockPaddle6()
{
}

void ClockPaddle6::Start()
{
	ClockPaddle6s = Init(ClockPaddle6s, "CodePaddle06.png", { 90,90 }, { 80,40 });
	ClockPaddle6sCollision = CollisionInit(ClockPaddle6sCollision, { 90,90 }, { 80,40 });
}

void ClockPaddle6::Update(float _DeltaTime)
{

}

void ClockPaddle6::Render(float _Delta)
{

};
