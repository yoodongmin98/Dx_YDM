#include "PrecompileHeader.h"
#include "BackCurtain_Main.h"
#include "ActorTypeEnum.h"
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

BackCurtain_Main::BackCurtain_Main()
{
}

BackCurtain_Main::~BackCurtain_Main()
{
}


void BackCurtain_Main::Start()
{
	//distortion shader�����ؾ���
	LeftCurtain = Init(LeftCurtain, "Rideaux.png", { 708.0f, 720.0f,1.0f }, { -290.0f,0.0f,0.0f });
	RightCurtain = Init(LeftCurtain, "Rideaux.png", { 708.0f, 720.0f,1.0f }, { 290.0f,0.0f,0.0f });
	RightCurtain->SetFlipX();
}

void BackCurtain_Main::Update(float _DeltaTime)
{

}

void BackCurtain_Main::Render(float _Delta)
{

};



