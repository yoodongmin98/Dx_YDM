#include "PrecompileHeader.h"
#include "ClockPaddle0.h"

//PlatForm
//Core




ClockPaddle0::ClockPaddle0()
{
}

ClockPaddle0::~ClockPaddle0()
{
}

void ClockPaddle0::Start()
{
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle0s = Init(ClockPaddle0s, "CodePaddle00.png", { 90,90 }, { 0,-120 });
}

void ClockPaddle0::Update(float _DeltaTime)
{

}

void ClockPaddle0::Render(float _Delta)
{

};
