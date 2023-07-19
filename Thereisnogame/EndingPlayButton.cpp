#include "PrecompileHeader.h"
#include "EndingPlayButton.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

EndingPlayButton::EndingPlayButton()
{
}

EndingPlayButton::~EndingPlayButton()
{
}

bool EndingAnimationImageBool = true;
void EndingPlayButton::Start()
{
	if (true == EndingAnimationImageBool)
	{
		AnimationImageLoad("EndingPlayButton");
		EndingAnimationImageBool = false;
	}

	Button = AnimationInit(Button, "End_BoutonPlay_Opened01.png", { 259,131 }, float4::Up * 50, "OpenButton", "EndingPlayButton", 4, 0.1f, false);
	Font = FontCreate(Font, 30, "PLAY", float4::Up * 170, GetTransform(), 1);
}

void EndingPlayButton::Update(float _DeltaTime)
{

}

void EndingPlayButton::Render(float _Delta)
{

};


