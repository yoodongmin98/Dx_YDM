#include "PrecompileHeader.h"
#include "ClockPaddle6.h"

//PlatForm
//Core




ClockPaddle6::ClockPaddle6()
{
}

ClockPaddle6::~ClockPaddle6()
{
}

void ClockPaddle6::Start()
{
	//�갡 ����number�����ؾ��ϴµ� ���߿� �����غ����ҵ�
	ClockPaddle6s = Init(ClockPaddle6s, "CodePaddle06.png", { 90,90 }, { 80,0 });
}

void ClockPaddle6::Update(float _DeltaTime)
{

}

void ClockPaddle6::Render(float _Delta)
{

};
