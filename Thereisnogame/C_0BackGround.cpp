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
	
}

void C_0BackGround::Render(float _Delta)
{
	
};
