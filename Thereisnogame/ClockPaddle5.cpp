#include "PrecompileHeader.h"
#include "ClockPaddle5.h"

//PlatForm
//Core




ClockPaddle5::ClockPaddle5()
{
}

ClockPaddle5::~ClockPaddle5()
{
}

void ClockPaddle5::Start()
{
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle5s = Init(ClockPaddle5s, "CodePaddle05.png", { 90,90 }, { 0,0 });
}

void ClockPaddle5::Update(float _DeltaTime)
{

}

void ClockPaddle5::Render(float _Delta)
{

};
