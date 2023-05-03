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
#include "Arrow.h"
#include "Panel_Continue.h"
#include "Panel_Back.h"

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
		CreateLetter();
		PanelContinuePtr = CreateActor<Panel_Continue>();
		PanelBackPtr=CreateActor<Panel_Back>();
		SelectBoxPtr=CreateActor<SelectBox>();
		CreateMainMenuArrow();
		//CreateActor<AlphaCircle>();
	}
	


	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("CameraSet", '0'); //알파벳
		GameEngineInput::CreateKey("PanelTestkey", '1');
		GameEngineInput::CreateKey("PanelTestkey2", '2');
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
	if (GameEngineInput::IsDown("PanelTestkey2"))
	{
		ChangeState(MainMenuState::DrawaPixel);
	}
	if (GameEngineInput::IsDown("PanelTestkey"))
	{
		ChangeState(MainMenuState::Flag);
	}
	
}

void MainMenuLevel::CreateMainMenuArrow()
{
	std::shared_ptr<Arrow> Arrow1 = CreateActor<Arrow>();
	Arrow1->GetTransform()->SetLocalPosition({ 140 ,-205,0 });
	Arrow1->GetTransform()->SetLocalRotation({ 0, 0, -40 });
	ArrowVector.push_back(Arrow1);

	std::shared_ptr<Arrow> Arrow2 = CreateActor<Arrow>();
	Arrow2->GetTransform()->SetLocalPosition({ 230 ,-155,0 });
	Arrow2->GetTransform()->SetLocalRotation({ 0, 0, -85 });
	ArrowVector.push_back(Arrow2);

	std::shared_ptr<Arrow> Arrow3 = CreateActor<Arrow>();
	Arrow3->GetTransform()->SetLocalPosition({ 440 ,-160,0 });
	Arrow3->GetTransform()->SetLocalRotation({ 0, 0, -120 });
	ArrowVector.push_back(Arrow3);

	std::shared_ptr<Arrow> Arrow4 = CreateActor<Arrow>();
	Arrow4->GetTransform()->SetLocalPosition({ 500 ,-220,0 });
	Arrow4->GetTransform()->SetLocalRotation({ 0, 0, -150 });
	ArrowVector.push_back(Arrow4);

	std::shared_ptr<Arrow> Arrow5 = CreateActor<Arrow>();
	Arrow5->GetTransform()->SetLocalPosition({ 500 ,-360,0 });
	Arrow5->GetTransform()->SetLocalRotation({ 0, 0, -200 });
	ArrowVector.push_back(Arrow5);
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

void MainMenuLevel::LetterDownfunction(float _DeltaTime)
{
	for (size_t i = 0; i < LetterVector.size(); i++)
	{
		LetterVector[i].get()->Down(_DeltaTime);
	}
}

void MainMenuLevel::LetterUpfunction(float _DeltaTime)
{
	for (size_t i = 0; i < LetterVector.size(); i++)
	{
		LetterVector[i].get()->Up(_DeltaTime);
	}
}