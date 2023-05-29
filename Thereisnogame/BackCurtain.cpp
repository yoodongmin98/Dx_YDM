#include "PrecompileHeader.h"
#include "BackCurtain.h"

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
	LeftCurtain = Init(LeftCurtain, "Rideaux.png", { 708.0f, 720.0f,1.0f }, { -290.0f,0.0f,0.0f });

	RightCurtain = Init(RightCurtain, "Rideaux.png", { 708.0f, 720.0f,1.0f }, { 290.0f,0.0f,0.0f });
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
		LeftCurtain->GetTransform()->AddLocalPosition({ -1,0,0 });
	}
	if (RightCurtain->GetTransform()->GetLocalPosition().x < 1000.0f)
	{
		RightCurtain->GetTransform()->AddLocalPosition({ 1,0,0 });
	}
}
void BackCurtain::CurtainClose()
{

}
