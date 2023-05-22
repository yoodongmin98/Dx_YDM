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
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle9s = Init(ClockPaddle9s, "CodePaddle09.png", { 90,90 }, {80,-40});
}

void ClockPaddle9::Update(float _DeltaTime)
{

}

void ClockPaddle9::Render(float _Delta)
{

};
