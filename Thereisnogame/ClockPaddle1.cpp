#include "PrecompileHeader.h"
#include "ClockPaddle1.h"

//PlatForm
//Core




ClockPaddle1::ClockPaddle1()
{
}

ClockPaddle1::~ClockPaddle1()
{
}

void ClockPaddle1::Start()
{
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle1s = Init(ClockPaddle1s, "CodePaddle01.png", { 90,90 }, { -80,120 });
}

void ClockPaddle1::Update(float _DeltaTime)
{

}

void ClockPaddle1::Render(float _Delta)
{

};
