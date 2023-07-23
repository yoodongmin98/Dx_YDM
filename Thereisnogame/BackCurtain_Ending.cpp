#include "PrecompileHeader.h"
#include "BackCurtain_Ending.h"
#include "ActorTypeEnum.h"
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

BackCurtain_Ending::BackCurtain_Ending()
{
}

BackCurtain_Ending::~BackCurtain_Ending()
{
}


void BackCurtain_Ending::Start()
{
	//distortion shader적용해야함
	LeftCurtain = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Curtain);
	LeftCurtain->SetScaleToTexture("RideauxDarker.png");
	LeftCurtain->GetTransform()->SetLocalScale({ 708.0f, 720.0f,1.0f });
	LeftCurtain->GetTransform()->SetLocalPosition({ -290.0f,0.0f,0.0f });

	RightCurtain = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Curtain);
	RightCurtain->SetScaleToTexture("RideauxDarker.png");
	RightCurtain->GetTransform()->SetLocalScale({ 708.0f, 720.0f,1.0f });
	RightCurtain->GetTransform()->SetLocalPosition({ 290.0f,0.0f,0.0f });
	RightCurtain->SetFlipX();
}

void BackCurtain_Ending::Update(float _DeltaTime)
{

}

void BackCurtain_Ending::Render(float _Delta)
{

};

//Functional 호출용(Chapter1)
void BackCurtain_Ending::CurtainOpen()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (LeftCurtain->GetTransform()->GetLocalPosition().x > -1000.0f)
	{
		LeftCurtain->GetTransform()->AddLocalPosition({ -1.0f * Times,0,0 });
	}
	if (RightCurtain->GetTransform()->GetLocalPosition().x < 1000.0f)
	{
		RightCurtain->GetTransform()->AddLocalPosition({ 1.0f * Times,0,0 });
	}
}
void BackCurtain_Ending::CurtainClose()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (LeftCurtain->GetTransform()->GetLocalPosition().x < -310.0f)
	{
		LeftCurtain->GetTransform()->AddLocalPosition({ 15.0f * Times,0,0 });
	}
	if (RightCurtain->GetTransform()->GetLocalPosition().x > 310.0f)
	{
		RightCurtain->GetTransform()->AddLocalPosition({ -15.0f * Times,0,0 });
	}
}
