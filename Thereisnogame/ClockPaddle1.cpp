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
	//�갡 ����number�����ؾ��ϴµ� ���߿� �����غ����ҵ�
	ClockPaddle1s = Init(ClockPaddle1s, "CodePaddle01.png", { 90,90 }, { -80,80 });
}

void ClockPaddle1::Update(float _DeltaTime)
{

}

void ClockPaddle1::Render(float _Delta)
{

};