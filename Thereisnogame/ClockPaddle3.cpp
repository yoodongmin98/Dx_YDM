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
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle3s = Init(ClockPaddle3s, "CodePaddle03.png", { 90,90 }, { 80,80 });
}

void ClockPaddle3::Update(float _DeltaTime)
{

}

void ClockPaddle3::Render(float _Delta)
{

};
