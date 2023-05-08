#include "PrecompileHeader.h"
#include "MainMenuLevel.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>


//Actor
#include "BackCurtain.h"
#include "AlphaCircle.h"
#include "SelectBox.h"
#include "Panel_Continue.h"
#include "Panel_Back.h"
#include "DrawaPixel.h"
#include "StartPictures.h"

//Letter
#include "C_0Letter_T.h"
#include "C_0Letter_H .h"
#include "C_0Letter_E.h"
#include "C_0Letter_R.h"
#include "C_0Letter_sE.h"
#include "C_0Letter_I.h"
#include "C_0Letter_S.h"
#include "C_0Letter_N.h"
#include "C_0Letter_O.h"
#include "C_0Letter_G.h"
#include "C_0Letter_A.h"
#include "C_0Letter_M.h"
#include "C_0Letter_e2.h"

//Arrow
#include "Arrow.h"
#include "Arrow1.h"
#include "Arrow2.h"
#include "Arrow3.h"
#include "Arrow4.h"

//Flag
#include "F_Brazilian.h"
#include "F_Chinese.h"
#include "F_English.h"
#include "F_French.h"
#include "F_German.h"
#include "F_Italian.h"
#include "F_Japan.h"
#include "F_Korea.h"
#include "F_Russian.h"
#include "F_Spanish.h"


MainMenuLevel::MainMenuLevel()
{
}

MainMenuLevel::~MainMenuLevel()
{
}

void MainMenuLevel::Start()
{
	//ImageLoad
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter0(MainMenu)");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	//백그라운드부터 순서대로(나중에 렌더될수록 가장 앞으로나옴)
	{
		CreateActor<BackCurtain>();
		CreateFlag();
		CreateLetter();
		PanelContinuePtr = CreateActor<Panel_Continue>();
		PanelBackPtr=CreateActor<Panel_Back>();
		SelectBoxPtr=CreateActor<SelectBox>();
		CreateMainMenuArrow();
		PixelPtr=CreateActor<Panel_DrawaPixel>();
		PicturesPtr=CreateActor<StartPictures>();
		//CreateActor<AlphaCircle>();
	}
	


	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("CameraSet", '0'); //알파벳
		GameEngineInput::CreateKey("TestKey1", '1');
		GameEngineInput::CreateKey("TestKey2", '2');
		GameEngineInput::CreateKey("TestKey3", '3');
		GameEngineInput::CreateKey("TestKey4", '4');
	}
	ChangeState(MainMenuState::Flag);

}

void MainMenuLevel::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);
	if (GameEngineInput::IsDown("CameraSet"))
	{
		GetMainCamera()->SetProjectionType(CameraType::Perspective);
		
	}
	//테스트용
	if (GameEngineInput::IsDown("TestKey3"))
	{
		ChangeState(MainMenuState::Menu);
	}
	if (GameEngineInput::IsDown("TestKey4"))
	{
		ChangeState(MainMenuState::Select);
	}
	
}

void MainMenuLevel::CreateFlag()
{
	FlagVector.push_back(CreateActor<F_Chinese>());
	FlagVector.push_back(CreateActor<F_French>());
	FlagVector.push_back(CreateActor<F_Japan>());

	FlagVector.push_back(CreateActor<F_Italian>());
	FlagVector.push_back(CreateActor<F_German>());
	FlagVector.push_back(CreateActor<F_Brazilian>());
	FlagVector.push_back(CreateActor<F_Russian>());

	FlagVector.push_back(CreateActor<F_Korea>());
	FlagVector.push_back(CreateActor<F_Spanish>());
	FlagVector.push_back(CreateActor<F_English>());
}

void MainMenuLevel::CreateMainMenuArrow()
{
	ArrowVector.push_back(CreateActor<Arrow>());
	ArrowVector.push_back(CreateActor<Arrow1>());
	ArrowVector.push_back(CreateActor<Arrow2>());
	ArrowVector.push_back(CreateActor<Arrow3>());
	ArrowVector.push_back(CreateActor<Arrow4>());
}

void MainMenuLevel::CreateLetter()
{
	LetterVector.push_back(CreateActor<C_Letter_O>());
	LetterVector.push_back(CreateActor<C_Letter_N>());
	
	LetterVector.push_back(CreateActor<C_Letter_A>());
	LetterVector.push_back(CreateActor<C_Letter_G>());
	LetterVector.push_back(CreateActor<C_Letter_e2>());
	LetterVector.push_back(CreateActor<C_Letter_M>());
	
	LetterVector.push_back(CreateActor<C_Letter_H>());
	LetterVector.push_back(CreateActor<C_Letter_T>());
	LetterVector.push_back(CreateActor<C_Letter_R>());
	LetterVector.push_back(CreateActor<C_Letter_E>());
	LetterVector.push_back(CreateActor<C_Letter_sE>());
	
	LetterVector.push_back(CreateActor<C_Letter_S>());
	LetterVector.push_back(CreateActor<C_Letter_I>());
}

void MainMenuLevel::Letterfunction(float _DeltaTime)
{
	switch (StateValue)
	{
	case MainMenuState::Menu:
		for (size_t i = 0; i < LetterVector.size(); i++)
		{
			LetterVector[i].get()->Down(_DeltaTime);
		}
		break;
	case MainMenuState::Select:
		for (size_t i = 0; i < LetterVector.size(); i++)
		{
			LetterVector[i].get()->Up(_DeltaTime);
		}
		break;
	default:
		break;
	}
}


void MainMenuLevel::Arrowfunction(float _DeltaTime)
{
	switch (StateValue)
	{
	case MainMenuState::Menu:
		for (size_t i = 0; i < ArrowVector.size(); i++)
		{
			if (MenuTime > 6.0f)
			{
				ArrowVector[i].get()->Up(_DeltaTime);
			}
		}
		break;
	case MainMenuState::Flag:
	case MainMenuState::DrawaPixel:
	case MainMenuState::Select:
		for (size_t i = 0; i < ArrowVector.size(); i++)
		{
			ArrowVector[i].get()->Down(_DeltaTime);
		}
		break;
	default:
		break;
	}
}

void MainMenuLevel::Flagfunction(float _DeltaTime)
{
	switch (StateValue)
	{
	case MainMenuState::Flag:
		for (size_t i = 0; i < FlagVector.size(); i++)
		{
			float FlagValue=FlagValueSet(1,i);
			FlagVector[i].get()->FlagDown(FlagValue,_DeltaTime);
		}
		break;
	case MainMenuState::DrawaPixel:
	case MainMenuState::Menu:
	case MainMenuState::Select:
		for (size_t i = 0; i < FlagVector.size(); i++)
		{
			float FlagValues = FlagValueSet(2, i);
			FlagVector[i].get()->FlagUp(FlagValues,_DeltaTime);
		}
		break;
	default:
		break;
	}
}

float MainMenuLevel::FlagValueSet(int SetValue,int _iValue)
{
	if (1 == SetValue)
	{
		switch (_iValue)
		{
		case 0:
			return 730.0f;
			break;
		case 1:
			return 670.0f;
			break;
		case 2:
			return 730.0f;
			break;
		case 3:
			return 530.0f;
			break;
		case 4:
			return 480.0f;
			break;
		case 5:
			return 570.0f;
			break;
		case 6:
			return 500.0f;
			break;
		case 7:
			return 300.0f;
			break;
		case 8:
			return 300.0f;
			break;
		case 9:
			return 380.0f;
			break;
		default:
			break;
		}
	}
	if (2 == SetValue)
	{
		switch (_iValue)
		{
		case 0:
			return 330.0f;
			break;
		case 1:
			return 50.0f;
			break;
		case 2:
			return -480.0f;
			break;
		case 3:
			return 920.0f;
			break;
		case 4:
			return 480.0f;
			break;
		case 5:
			return -370.0f;
			break;
		case 6:
			return -600.0f;
			break;
		case 7:
			return 530.0f; 
			break;
		case 8:
			return -510.0f;
			break;
		case 9:
			return -70.0f;
			break;
		default:
			break;
		}
	}
	
}
