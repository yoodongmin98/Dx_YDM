#include "PrecompileHeader.h"
#include "MainMenuLevel.h"

#include <functional>
//Platform
#include <GameEnginePlatform/GameEngineInput.h>
//Core
//Actor
#include "Panel_Continue.h"
#include "Panel_Back.h"
#include "SelectBox.h"
#include "Arrow.h"
#include "DrawaPixel.h"
#include "StartPictures.h"



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

bool FlagCreateBool = false;
void MainMenuLevel::FlagStart()
{
	
}
void MainMenuLevel::FlagUpdate(float _DeltaTime)
{
	FlagTime += _DeltaTime; //Phase Time

	if (FlagTime > 1.0f)
	{
		if (false == FlagCreateBool)
		{
			CreateFlag();
			FlagCreateBool = true;
		}
		Flagfunction(_DeltaTime);
		if (true==IsClicktheFlag) 
		{
			ChangeState(MainMenuState::DrawaPixel);
			Play(MainEtcSound, "MainMenu_LanguageOut.wav", 0.1f);
		}
	}
}
void MainMenuLevel::FlagEnd()
{
	
}

bool PixelPanel = false;
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
		if (false == PixelPanel)
		{
			PixelPtr = CreateActor<Panel_DrawaPixel>();
			PixelPanel = true;
		}
		//잘못짰는데 되긴하니까 넘어가자..
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
	Play(MainEtcSound, "MainMenu_TitleIn.wav", 0.1f);
	CreateLetter();
}
void MainMenuLevel::MenuUpdate(float _DeltaTime)
{
	IsClickBackPanel = false;
	MenuTime += _DeltaTime;
	Letterfunction(_DeltaTime);
	Arrowfunction(_DeltaTime);
	Flagfunction(_DeltaTime);

	

	std::function<void(float)> MenuFunctional;

	MenuFunctional = std::bind(&Panel_Continue::RZRotations, PanelContinuePtr.get(), std::placeholders::_1);
	MenuFunctional(_DeltaTime);

	MenuFunctional = std::bind(&Panel_Back::RZRotations, PanelBackPtr.get(), std::placeholders::_1);
	MenuFunctional(_DeltaTime);
	if (nullptr != PicturesPtr)
	{
		MenuFunctional = std::bind(&StartPictures::PictureUp, PicturesPtr.get(), std::placeholders::_1);
		MenuFunctional(_DeltaTime);
	}

	if (MenuTime > 5.0f)
	{
		if (GameEngineInput::IsDown("LeftMouse"))
		{
			if (false == ArrowCreateBool)
			{
				Play(MainEtcSound, "MainMenu_Click.wav", 0.1f);
				SelectBoxPtr = CreateActor<SelectBox>();
				CreateMainMenuArrow();
				ArrowCreateBool = true;
			}
		}
		if (true == ArrowCreateBool)
		{
			MenuFunctional = std::bind(&SelectBox::Up, SelectBoxPtr.get(), std::placeholders::_1);
			MenuFunctional(_DeltaTime);
		}
		
		if (true == IsClickStartButton)
		{
			if (nullptr != PicturesPtr)
			{
				PicturesPtr.get()->Death();
			}
			Play(MainEtcSound, "MainMenu_Click02.wav", 0.1f);
			Play(MainEtcSound, "MainMenu_PanelChoiceOut.wav", 0.1f);
			ChangeState(MainMenuState::Select);
		}
	}
	
}
void MainMenuLevel::MenuEnd()
{

}


void MainMenuLevel::SelectStart()
{
	PicturesPtr = CreateActor<StartPictures>();
}
void MainMenuLevel::SelectUpdate(float _DeltaTime)
{
	ArrowCreateBool = false;
	IsClickStartButton = false;
	Letterfunction(_DeltaTime);
	Arrowfunction(_DeltaTime);
	Flagfunction(_DeltaTime);
	std::function<void(float)> SelectFunctional;

	SelectFunctional = std::bind(&Panel_Continue::ZRotations, PanelContinuePtr.get(), std::placeholders::_1);
	SelectFunctional(_DeltaTime);

	SelectFunctional = std::bind(&Panel_Back::ZRotations, PanelBackPtr.get(), std::placeholders::_1);
	SelectFunctional(_DeltaTime);

	SelectFunctional = std::bind(&SelectBox::Down, SelectBoxPtr.get(), std::placeholders::_1);
	SelectFunctional(_DeltaTime);

	SelectFunctional = std::bind(&StartPictures::PictureDown, PicturesPtr.get(), std::placeholders::_1);
	SelectFunctional(_DeltaTime);

	if (true == IsClickBackPanel)
	{
		ArrowCreateBool = false;
		SelectBoxPtr.get()->Death();
		for (size_t i = 0; i < ArrowVector.size(); i++)
		{
			ArrowVector[i].get()->Death();
		}
		for (size_t i = 0; i < LetterVector.size(); i++)
		{
			LetterVector[i].get()->Death();
		}
		ChangeState(MainMenuState::Menu);
	}
}
void MainMenuLevel::SelectEnd()
{

}
