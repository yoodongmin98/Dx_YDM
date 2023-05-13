#include "PrecompileHeader.h"
#include "ClockPaddle4.h"

//PlatForm
//Core




ClockPaddle4::ClockPaddle4()
{
}

ClockPaddle4::~ClockPaddle4()
{
}

void ClockPaddle4::Start()
{
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle4s = Init(ClockPaddle4s, "CodePaddle04.png", { 90,90 }, { -80,0 });
}

void ClockPaddle4::Update(float _DeltaTime)
{

}

void ClockPaddle4::Render(float _Delta)
{

};
