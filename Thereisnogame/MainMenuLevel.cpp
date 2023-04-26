#include "PrecompileHeader.h"
#include "MainMenuLevel.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>

//Actor
#include "C_0BackGround.h"
#include "C_0Letter_T.h"

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

	CreateActor<C_0BackGround>();
	CreateActor<C_Letter_T>();


	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("CameraSet", '1');
		GameEngineInput::CreateKey("PlayerMoveLeft", 'A');
		GameEngineInput::CreateKey("PlayerMoveRight", 'D');
		GameEngineInput::CreateKey("PlayerMoveUp", 'Q');
		GameEngineInput::CreateKey("PlayerMoveDown", 'E');
		GameEngineInput::CreateKey("PlayerMoveForward", 'W');
		GameEngineInput::CreateKey("PlayerMoveBack", 'S');

		GameEngineInput::CreateKey("PlayerScaleY+", 'Y');
		GameEngineInput::CreateKey("PlayerScaleY-", 'U');
		GameEngineInput::CreateKey("PlayerScaleZ+", 'H');
		GameEngineInput::CreateKey("PlayerScaleZ-", 'J');
		GameEngineInput::CreateKey("PlayerScaleX+", 'N');
		GameEngineInput::CreateKey("PlayerScaleX-", 'M');


		GameEngineInput::CreateKey("PlayerRotY+", VK_NUMPAD1);
		GameEngineInput::CreateKey("PlayerRotY-", VK_NUMPAD2);
		GameEngineInput::CreateKey("PlayerRotZ+", VK_NUMPAD4);
		GameEngineInput::CreateKey("PlayerRotZ-", VK_NUMPAD5);
		GameEngineInput::CreateKey("PlayerRotX+", VK_NUMPAD7);
		GameEngineInput::CreateKey("PlayerRotX-", VK_NUMPAD8);
		GameEngineInput::CreateKey("PlayerSpeedBoost", VK_LSHIFT);
	}
}

void MainMenuLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("CameraSet"))
	{
		GetMainCamera()->SetProjectionType(CameraType::Perspective);
	}
}