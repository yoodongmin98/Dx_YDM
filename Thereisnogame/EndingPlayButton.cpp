#include "PrecompileHeader.h"
#include "EndingPlayButton.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "EndingLevel.h"
#include "LevelStateManager.h"
#include "FolderBackGround.h"

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

	Button = NoChangeAnimationInit(Button, "End_BoutonPlay_Closed1.png", { 259,131 }, {-60,50}, "OpenButton", "EndingPlayButton", 4, 0.1f, false);

	ButtonCollision = CollisionInit(ButtonCollision, { 144,131 }, float4::Up * 50);
	Font = FontCreate(Font, 30, "PLAY", float4::Up * 170, GetTransform(), 1);
}

void EndingPlayButton::Update(float _DeltaTime)
{
	if (true == ClickCheck(ButtonCollision)
		&& GetLiveTime() < 90.0f)
	{
		Play(Sound, "KnockGlass.wav", 0.1f);
	}
	if (GetLiveTime() > 90.0f)
	{
		static bool AniBool1 = true;
		if (true == AniBool1)
		{
			Button->ChangeAnimation("OpenButton");
			AniBool1 = false;
		}
		if (true == ClickCheck(ButtonCollision))
		{
			ButtonCollision->Death();
			GetLevel()->CreateActor<FolderBackGround>();
			LevelStateManager::MG->IsClickPlayButtonTrue();
			EndingLevel::EL->StopBGM();
			Play(Sound, "LumiereOn.wav", 0.1f);
		}
	}
}

void EndingPlayButton::Render(float _Delta)
{

};


