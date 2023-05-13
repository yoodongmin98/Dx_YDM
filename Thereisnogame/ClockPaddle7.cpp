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
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle7s = Init(ClockPaddle7s, "CodePaddle07.png", { 90,90 }, { -80,-80 });
}

void ClockPaddle7::Update(float _DeltaTime)
{

}

void ClockPaddle7::Render(float _Delta)
{

};
