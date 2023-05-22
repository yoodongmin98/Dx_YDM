#include "PrecompileHeader.h"
#include "ClockPaddle9.h"

//PlatForm
//Core




ClockPaddle9::ClockPaddle9()
{
}

ClockPaddle9::~ClockPaddle9()
{
}

void ClockPaddle9::Start()
{
	ClockPaddle9s = Init(ClockPaddle9s, "CodePaddle09.png", { 90,90 }, {80,-40});
	ClockPaddle9sCollision = CollisionInit(ClockPaddle9sCollision, { 90,90 }, { 80,-40 });
}

void ClockPaddle9::Update(float _DeltaTime)
{

}

void ClockPaddle9::Render(float _Delta)
{

};
