#include "PrecompileHeader.h"
#include "MainMenuLevel.h"

#include <functional>

#include "Panel_Continue.h"
#include "Panel_Back.h"
#include "SelectBox.h"
#include "Arrow.h"
#include "DrawaPixel.h"



void MainMenuLevel::ChangeState(MainMenuState _State)
{
	MainMenuState NextState = _State;
	MainMenuState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case MainMenuState::Flag:
		FlagStart();
		break;
	case MainMenuState::DrawaPixel:
		DrawaPixelStart();
		break;
	case MainMenuState::Menu:
		MenuStart();
		break;
	case MainMenuState::Select:
		SelectStart();
		break;

	}

	switch (PrevState)
	{
	case MainMenuState::Flag:
		FlagEnd();
		break;
	case MainMenuState::DrawaPixel:
		DrawaPixelEnd();
		break;
	case MainMenuState::Menu:
		MenuEnd();
		break;
	case MainMenuState::Select:
		SelectEnd();
		break;
	default:
		break;
	}
}

void MainMenuLevel::UpdateState(float _DeltaTime)
{
	switch (StateValue)
	{
	case MainMenuState::Flag:
		FlagUpdate(_DeltaTime);
		break;
	case MainMenuState::DrawaPixel:
		DrawaPixelUpdate(_DeltaTime);
		break;
	case MainMenuState::Menu:
		MenuUpdate(_DeltaTime);
		break;
	case MainMenuState::Select:
		SelectUpdate(_DeltaTime);
		break;
	default:
		break;
	}
}

void MainMenuLevel::FlagStart()
{
	
}
void MainMenuLevel::FlagUpdate(float _DeltaTime)
{
	FlagTime += _DeltaTime; //Phase Time

	if (FlagTime > 1.0f)
	{
		Flagfunction(_DeltaTime);
		if (FlagTime > 7.0f) //바꿔야할 부분(if mouse<->Collision이 충돌(클릭)을 한다면)
		{
			ChangeState(MainMenuState::DrawaPixel);
		}
	}
}
void MainMenuLevel::FlagEnd()
{

}


void MainMenuLevel::DrawaPixelStart()
{

}
void MainMenuLevel::DrawaPixelUpdate(float _DeltaTime)
{
	DrawaPixelTime += _DeltaTime; //Phase Time
	Flagfunction(_DeltaTime);

	std::function<void(float)> PixelFunctional;
	if (DrawaPixelTime > 3.0f)
	{
		PixelFunctional = std::bind(&Panel_DrawaPixel::Down, PixelPtr.get(), std::placeholders::_1);
		PixelFunctional(_DeltaTime);
		if (DrawaPixelTime > 7.0f)
		{
			PixelFunctional = std::bind(&Panel_DrawaPixel::Up, PixelPtr.get(), std::placeholders::_1);
			PixelFunctional(_DeltaTime);
			if (DrawaPixelTime > 10.0f)
			{
				ChangeState(MainMenuState::Menu);
			}
		}
	}
}
void MainMenuLevel::DrawaPixelEnd()
{

}


void MainMenuLevel::MenuStart()
{

}
void MainMenuLevel::MenuUpdate(float _DeltaTime)
{
	MenuTime += _DeltaTime;
	Letterfunction(_DeltaTime);
	Arrowfunction(_DeltaTime);
	Flagfunction(_DeltaTime);

	std::function<void(float)> FlagFunctional;

	FlagFunctional = std::bind(&Panel_Continue::RZRotations, PanelContinuePtr.get(), std::placeholders::_1);
	FlagFunctional(_DeltaTime);

	FlagFunctional = std::bind(&Panel_Back::RZRotations, PanelBackPtr.get(), std::placeholders::_1);
	FlagFunctional(_DeltaTime);
	//if(마우스왼쪽버튼을 누른다면)으로 바꾸기
	if (MenuTime > 6.0f)
	{
		FlagFunctional = std::bind(&SelectBox::Up, SelectBoxPtr.get(), std::placeholders::_1);
		FlagFunctional(_DeltaTime);
	}
	
}
void MainMenuLevel::MenuEnd()
{

}


void MainMenuLevel::SelectStart()
{

}
void MainMenuLevel::SelectUpdate(float _DeltaTime)
{
	Letterfunction(_DeltaTime);
	Arrowfunction(_DeltaTime);
	Flagfunction(_DeltaTime);
	std::function<void(float)> DrawaPixelFunctional;

	DrawaPixelFunctional = std::bind(&Panel_Continue::ZRotations, PanelContinuePtr.get(), std::placeholders::_1);
	DrawaPixelFunctional(_DeltaTime);

	DrawaPixelFunctional = std::bind(&Panel_Back::ZRotations, PanelBackPtr.get(), std::placeholders::_1);
	DrawaPixelFunctional(_DeltaTime);

	DrawaPixelFunctional = std::bind(&SelectBox::Down, SelectBoxPtr.get(), std::placeholders::_1);
	DrawaPixelFunctional(_DeltaTime);
}
void MainMenuLevel::SelectEnd()
{

}
