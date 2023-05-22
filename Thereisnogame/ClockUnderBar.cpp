#include "PrecompileHeader.h"
#include "ClockUnderBar.h"

//PlatForm
//Core



ClockUnderBar* ClockUnderBar::CM;
ClockUnderBar::ClockUnderBar()
{
	CM = this;
}

ClockUnderBar::~ClockUnderBar()
{
}

void ClockUnderBar::Start()
{
	ClockUnderBars1 = Init(ClockUnderBars1, "Chap04_MapBranchHorizontal.png", { 45,8 }, { -150,220 });
	ClockUnderBars2 = Init(ClockUnderBars2, "Chap04_MapBranchHorizontal.png", { 45,8 }, { -90,220 });
	ClockUnderBars3 = Init(ClockUnderBars3, "Chap04_MapBranchHorizontal.png", { 45,8 }, { -30,220 });
	ClockUnderBars4 = Init(ClockUnderBars4, "Chap04_MapBranchHorizontal.png", { 45,8 }, { 30,220 });
	ClockUnderBars5 = Init(ClockUnderBars5, "Chap04_MapBranchHorizontal.png", { 45,8 }, { 90,220 });
	ClockUnderBars6 = Init(ClockUnderBars6, "Chap04_MapBranchHorizontal.png", { 45,8 }, { 150,220 });

	PasswordUnderBar.push_back(ClockUnderBars1);
	PasswordUnderBar.push_back(ClockUnderBars2);
	PasswordUnderBar.push_back(ClockUnderBars3);
	PasswordUnderBar.push_back(ClockUnderBars4);
	PasswordUnderBar.push_back(ClockUnderBars5);
	PasswordUnderBar.push_back(ClockUnderBars6);
}

void ClockUnderBar::Update(float _DeltaTime)
{
	if (1==PassWordCheck.size())
	{
		int i = PassWordCheck[0];
		PasswordUnderBar[0].get()->Off();
	}
}

void ClockUnderBar::Render(float _Delta)
{

};

void ClockUnderBar::PushIntCheck(int _Value)
{
	/*switch (_Value)
	{
	case 1:
		ClockUnderBars1
	}*/
}