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
	//�갡 ����number�����ؾ��ϴµ� ���߿� �����غ����ҵ�
	ClockPaddle2s = Init(ClockPaddle2s, "CodePaddle02.png", { 90,90 }, { 0,80 });
}

void ClockPaddle2::Update(float _DeltaTime)
{

}

void ClockPaddle2::Render(float _Delta)
{

};
