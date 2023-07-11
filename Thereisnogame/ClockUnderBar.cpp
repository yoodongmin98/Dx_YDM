#include "PrecompileHeader.h"
#include "ClockUnderBar.h"

//PlatForm
//Core

//Actor
#include "LevelStateManager.h"


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

	PasswordSet(1,2,3,4,5,6);

	Font = FontCreate(Font, 25, "시간 시스템에 접속하려면 관리자 비밀번호가 필요합니다.", float4::Down * 200, GetTransform(), 2);
}

void ClockUnderBar::Update(float _DeltaTime)
{
	UnderBarOffAndCreateNumberRender();
	if (true == PasswordCheck())
	{
		Play(Sound, "DigicodeRight.wav", 0.1f);
		LevelStateManager::MG->PlusClockValue();
		LevelStateManager::MG->MinusCollisionValue();
		Death();
	}
	if (6==PassWordCheck.size()&&false == PasswordCheck())
	{
		Play(Sound, "DigicodeWrong.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		Death();
	}
}

void ClockUnderBar::Render(float _Delta)
{

};




//------------------------------------------------------------------------------------------------------------------------------------------

bool ClockUnderBar::PasswordCheck()
{
	if (PassWord == PassWordCheck)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClockUnderBar::PasswordSet(int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6)
{
	PassWord.push_back(_Value1);
	PassWord.push_back(_Value2);
	PassWord.push_back(_Value3);
	PassWord.push_back(_Value4);
	PassWord.push_back(_Value5);
	PassWord.push_back(_Value6);
}

void ClockUnderBar::UnderBarOffAndCreateNumberRender()
{
	if (0 != PassWordCheck.size())
	{
		for (size_t i = 0; i < PassWordCheck.size(); i++)
		{
			PasswordUnderBar[i].get()->Off();
		}
	}
}