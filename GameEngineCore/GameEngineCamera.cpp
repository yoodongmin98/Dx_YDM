#include "PrecompileHeader.h"
#include "GameEngineCamera.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "GameEngineDevice.h"

GameEngineCamera::GameEngineCamera()
{
}

GameEngineCamera::~GameEngineCamera()
{
}


void GameEngineCamera::Start()
{
	if (false == GameEngineInput::IsKey("CamMoveLeft"))
	{
		GameEngineInput::CreateKey("CamMoveLeft", 'A');
		GameEngineInput::CreateKey("CamMoveRight", 'D');
		GameEngineInput::CreateKey("CamMoveUp", 'Q');
		GameEngineInput::CreateKey("CamMoveDown", 'E');
		GameEngineInput::CreateKey("CamMoveForward", 'W');
		GameEngineInput::CreateKey("CamMoveBack", 'S');

		GameEngineInput::CreateKey("RotY+", VK_NUMPAD1);
		GameEngineInput::CreateKey("RotY-", VK_NUMPAD2);
		GameEngineInput::CreateKey("RotZ+", VK_NUMPAD4);
		GameEngineInput::CreateKey("RotZ-", VK_NUMPAD5);
		GameEngineInput::CreateKey("RotX+", VK_NUMPAD7);
		GameEngineInput::CreateKey("RotX-", VK_NUMPAD8);

		GameEngineInput::CreateKey("CamRot", VK_RBUTTON);
		GameEngineInput::CreateKey("SpeedBoost", VK_LSHIFT);
		GameEngineInput::CreateKey("FreeCameraSwitch", 'P');
		GameEngineInput::CreateKey("ProjectionModeChange", 'O');
	}

	// float _Width, float _Height, float _Left, float _Right, float _ZMin = 0.0f, float _ZMax = 1.0f

	ViewPortData.TopLeftX = 0;
	ViewPortData.TopLeftY = 0;
	ViewPortData.Width = GameEngineWindow::GetScreenSize().x;
	ViewPortData.Height = GameEngineWindow::GetScreenSize().y;
	ViewPortData.MinDepth = 0.0f;
	ViewPortData.MaxDepth = 1.0f;

	Width = ViewPortData.Width;
	Height = ViewPortData.Height;
}

void GameEngineCamera::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("ProjectionModeChange"))
	{
		switch (ProjectionType)
		{
		case CameraType::None:
			break;
		case CameraType::Perspective:
			ProjectionType = CameraType::Orthogonal;
			break;
		case CameraType::Orthogonal:
			ProjectionType = CameraType::Perspective;
			break;
		default:
			break;
		}
	}

	if (true == GameEngineInput::IsDown("FreeCameraSwitch"))
	{
		FreeCamera = !FreeCamera;

		if (true == FreeCamera)
		{
			OldData = GetTransform()->GetTransDataRef();
		}
		else {
			GetTransform()->SetTransformData(OldData);
		}
	}

	if (true == FreeCamera)
	{
		float RotSpeed = 180.0f;

		float Speed = 200.0f;

		if (true == GameEngineInput::IsPress("SpeedBoost"))
		{
			Speed = 1000.0f;
		}

		if (true == GameEngineInput::IsPress("CamMoveLeft"))
		{
			GetTransform()->AddLocalPosition(GetTransform()->GetWorldLeftVector()* Speed * _DeltaTime);
		}
		if (true == GameEngineInput::IsPress("CamMoveRight"))
		{
			GetTransform()->AddLocalPosition(GetTransform()->GetWorldRightVector() * Speed * _DeltaTime);
		}
		if (true == GameEngineInput::IsPress("CamMoveUp"))
		{
			GetTransform()->AddLocalPosition(GetTransform()->GetWorldUpVector() * Speed * _DeltaTime);
		}
		if (true == GameEngineInput::IsPress("CamMoveDown"))
		{
			GetTransform()->AddLocalPosition(GetTransform()->GetWorldDownVector() * Speed * _DeltaTime);
		}
		if (true == GameEngineInput::IsPress("CamMoveForward"))
		{
			GetTransform()->AddLocalPosition(GetTransform()->GetWorldForwardVector() * Speed * _DeltaTime);
		}
		if (true == GameEngineInput::IsPress("CamMoveBack"))
		{
			GetTransform()->AddLocalPosition(GetTransform()->GetWorldBackVector() * Speed * _DeltaTime);
		}

		if (true == GameEngineInput::IsPress("CamRot"))
		{
			float4 Dir = GameEngineInput::GetMouseDirectionNormal();

			float4 RotMouseDir;
			RotMouseDir.x = Dir.y;
			RotMouseDir.y = Dir.x;

			GetTransform()->AddWorldRotation(RotMouseDir);
		}

	}


	// ������� ����� ���ؼ��� �� 2���� ����� �ʿ��ϴ�.
	float4 EyeDir = GetTransform()->GetLocalForwardVector();
	float4 EyeUp = GetTransform()->GetLocalUpVector();
	float4 EyePos = GetTransform()->GetLocalPosition();

	View.LookToLH(EyePos, EyeDir, EyeUp);

	switch (ProjectionType)
	{
	case CameraType::None:
	{
		MsgAssert("ī�޶� ������ �������� �ʾҽ��ϴ�.");
		break;
	}
	case CameraType::Perspective:
		Projection.PerspectiveFovLH(FOV, Width / Height, Near, Far);
		break;
	case CameraType::Orthogonal:
		Projection.OrthographicLH(Width, Height, Near, Far);
		break;
	default:
		break;
	}

	ViewPort.ViewPort(GameEngineWindow::GetScreenSize().x, GameEngineWindow::GetScreenSize().y, 0.0f, 0.0f);
}


void GameEngineCamera::Setting()
{
	// ����Ÿ�� 1��1������ ����Ʈ�� �������ټ� �ִ�.
	GameEngineDevice::GetContext()->RSSetViewports(1, &ViewPortData);
}