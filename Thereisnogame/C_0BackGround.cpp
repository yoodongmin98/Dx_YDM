#include "PrecompileHeader.h"
#include "C_0BackGround.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_0BackGround::C_0BackGround()
{
}

C_0BackGround::~C_0BackGround()
{
}




void C_0BackGround::Start()
{
	LeftCurtain = CreateComponent<GameEngineSpriteRenderer>();
	LeftCurtain->SetTexture("Rideaux.png");
	LeftCurtain->GetTransform()->SetLocalScale({ 708.0f, 720.0f,1.0f });
	LeftCurtain->GetTransform()->SetLocalPosition({-290.0f,0.0f,0.0f});

	RightCurtain = CreateComponent<GameEngineSpriteRenderer>();
	RightCurtain->SetTexture("Rideaux.png");
	RightCurtain->GetTransform()->SetLocalScale({ 708.0f, 720.0f , 1.0f });
	RightCurtain->GetTransform()->SetLocalPosition({ 290.0f,0.0f,0.0f });
	RightCurtain->SetFlipX();
	
	
}

void C_0BackGround::Update(float _DeltaTime)
{
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

void C_0BackGround::Render(float _Delta)
{
	
};
