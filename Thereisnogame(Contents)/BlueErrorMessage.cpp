#include "PrecompileHeader.h"
#include "BlueErrorMessage.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "FadeEffect.h"

BlueErrorMessage::BlueErrorMessage()
{
}

BlueErrorMessage::~BlueErrorMessage()
{
}

void BlueErrorMessage::Start()
{
	BlueErrorMessages = Init(BlueErrorMessages, "End_ErrorMessage.png", { 1280,720 }, { 0,0,0 });
}

void BlueErrorMessage::Update(float _DeltaTime)
{
	if (GetLiveTime() > 4.0f)
	{
		GameEngineCore::ChangeLevel("MainMenuLevel");
	}
}

void BlueErrorMessage::Render(float _Delta)
{

};

