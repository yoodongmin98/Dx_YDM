#include "PrecompileHeader.h"
#include "BackCurtain.h"
#include "ActorTypeEnum.h"
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

BackCurtain::BackCurtain()
{
}

BackCurtain::~BackCurtain()
{
}


void BackCurtain::Start()
{
	//distortion shader적용해야함
	LeftCurtain = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Curtain);
	LeftCurtain->SetScaleToTexture("Rideaux.png");
	LeftCurtain->GetTransform()->SetLocalScale({ 708.0f, 720.0f,1.0f });
	LeftCurtain->GetTransform()->SetLocalPosition({ -290.0f,0.0f,0.0f });

	RightCurtain = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Curtain);
	RightCurtain->SetScaleToTexture("Rideaux.png");
	RightCurtain->GetTransform()->SetLocalScale({ 708.0f, 720.0f,1.0f });
	RightCurtain->GetTransform()->SetLocalPosition({ 290.0f,0.0f,0.0f });
	RightCurtain->SetFlipX();
}

void BackCurtain::Update(float _DeltaTime)
{
	
}

void BackCurtain::Render(float _Delta)
{
	
};

//Functional 호출용(Chapter1)
void BackCurtain::CurtainOpen()
{
	if (LeftCurtain->GetTransform()->GetLocalPosition().x > -1000.0f)
	{
		LeftCurtain->GetTransform()->AddLocalPosition({ -2.5f,0,0 });
	}
	if (RightCurtain->GetTransform()->GetLocalPosition().x < 1000.0f)
	{
		RightCurtain->GetTransform()->AddLocalPosition({ 2.5f,0,0 });
	}
}
void BackCurtain::CurtainClose()
{
	if (LeftCurtain->GetTransform()->GetLocalPosition().x < -290.0f)
	{
		LeftCurtain->GetTransform()->AddLocalPosition({ 15.0f,0,0 });
	}
	if (RightCurtain->GetTransform()->GetLocalPosition().x > 290.0f)
	{
		RightCurtain->GetTransform()->AddLocalPosition({ -15.0f,0,0 });
	}
}
