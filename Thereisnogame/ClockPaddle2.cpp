#include "PrecompileHeader.h"
#include "ClockPaddle2.h"

//PlatForm
//Core




ClockPaddle2::ClockPaddle2()
{
}

ClockPaddle2::~ClockPaddle2()
{
}

void ClockPaddle2::Start()
{
	//얘가 위에number생성해야하는데 나중에 연구해봐야할듯
	ClockPaddle2s = Init(ClockPaddle2s, "CodePaddle02.png", { 90,90 }, { 0,80 });
}

void ClockPaddle2::Update(float _DeltaTime)
{

}

void ClockPaddle2::Render(float _Delta)
{

};
