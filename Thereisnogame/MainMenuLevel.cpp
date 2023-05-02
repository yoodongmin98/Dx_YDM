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
		CreateActor<SelectBox>();
		CreateMainMenuArrow();
		CreateActor<AlphaCircle>();
	}
	


	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("CameraSet", '0');
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


		GameEngineInput::CreateKey("PlayerRotY+", '1');
		GameEngineInput::CreateKey("PlayerRotY-", '2');
		GameEngineInput::CreateKey("PlayerRotZ+", '3');
		GameEngineInput::CreateKey("PlayerRotZ-", '4');
		GameEngineInput::CreateKey("PlayerRotX+", '5');
		GameEngineInput::CreateKey("PlayerRotX-", '6');
		GameEngineInput::CreateKey("PlayerSpeedBoost", VK_LSHIFT);
	}
}

void MainMenuLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("CameraSet"))
	{
		GetMainCamera()->SetProjectionType(CameraType::Perspective);
	}
	float RotSpeed = 180.0f;

	float Speed = 200.0f;

	if (true == GameEngineInput::IsPress("PlayerSpeedBoost"))
	{
		Speed = 500.0f;
	}

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		GetTransform()->AddLocalPosition(float4::Up * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		GetTransform()->AddLocalPosition(float4::Down * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveForward"))
	{
		GetTransform()->AddLocalPosition(GetTransform()->GetLocalForwardVector() * Speed * _DeltaTime);
		// GetTransform()->AddLocalPosition(float4::Forward * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveBack"))
	{
		GetTransform()->AddLocalPosition(float4::Back * Speed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("PlayerRotY+"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, RotSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerRotY-"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, -RotSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerRotZ+"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, 0.0f, RotSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerRotZ-"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, 0.0f, -RotSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerRotX+"))
	{
		GetTransform()->AddLocalRotation({ RotSpeed * _DeltaTime, 0.0f, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerRotX-"))
	{
		GetTransform()->AddLocalRotation({ -RotSpeed * _DeltaTime, 0.0f, 0.0f });
	}

	float ScaleSpeed = 10.0f;

	if (true == GameEngineInput::IsPress("PlayerScaleY+"))
	{
		GetTransform()->AddLocalScale({ 0.0f, ScaleSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleY-"))
	{
		GetTransform()->AddLocalScale({ 0.0f, -ScaleSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleZ+"))
	{
		GetTransform()->AddLocalScale({ 0.0f, 0.0f, ScaleSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleZ-"))
	{
		GetTransform()->AddLocalScale({ 0.0f, 0.0f, -ScaleSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleX+"))
	{
		GetTransform()->AddLocalScale({ ScaleSpeed * _DeltaTime, 0.0f, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleX-"))
	{
		GetTransform()->AddLocalScale({ -ScaleSpeed * _DeltaTime, 0.0f, 0.0f });
	}
}

void MainMenuLevel::CreateMainMenuArrow()
{
	std::shared_ptr<Arrow> Arrow1 = CreateActor<Arrow>();
	Arrow1->GetTransform()->SetLocalPosition({ 140 ,-205,0 });
	Arrow1->GetTransform()->SetLocalRotation({ 0, 0, -40 });

	std::shared_ptr<Arrow> Arrow2 = CreateActor<Arrow>();
	Arrow2->GetTransform()->SetLocalPosition({ 230 ,-155,0 });
	Arrow2->GetTransform()->SetLocalRotation({ 0, 0, -85 });

	std::shared_ptr<Arrow> Arrow3 = CreateActor<Arrow>();
	Arrow3->GetTransform()->SetLocalPosition({ 440 ,-160,0 });
	Arrow3->GetTransform()->SetLocalRotation({ 0, 0, -120 });

	std::shared_ptr<Arrow> Arrow4 = CreateActor<Arrow>();
	Arrow4->GetTransform()->SetLocalPosition({ 500 ,-220,0 });
	Arrow4->GetTransform()->SetLocalRotation({ 0, 0, -150 });

	std::shared_ptr<Arrow> Arrow5 = CreateActor<Arrow>();
	Arrow5->GetTransform()->SetLocalPosition({ 500 ,-360,0 });
	Arrow5->GetTransform()->SetLocalRotation({ 0, 0, -200 });

}

void MainMenuLevel::CreateLetter()
{
	CreateActor<C_Letter_O>();
	CreateActor<C_Letter_N>();

	CreateActor<C_Letter_A>();
	CreateActor<C_Letter_G>();
	CreateActor<C_Letter_e2>();
	CreateActor<C_Letter_M>();

	CreateActor<C_Letter_H>();
	CreateActor<C_Letter_T>();
	CreateActor<C_Letter_R>();
	CreateActor<C_Letter_E>();
	CreateActor<C_Letter_sE>();

	CreateActor<C_Letter_S>();
	CreateActor<C_Letter_I>();

	
}