#include "PrecompileHeader.h"
#include "EndingLevel.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>

//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
#include "FadeEffect.h"
#include "C1_BackGround.h"
#include "BackCurtain_Ending.h"
#include "SoundAndTextActor.h"
#include "EndingPlayButton.h"
#include "AlphaCircle.h"
#include "EndingDeleteButton.h"
#include "PlaySmallArrow.h"
#include "DeleteArrow.h"

EndingLevel* EndingLevel::EL;

EndingLevel::EndingLevel()
{
	EL = this;
}

EndingLevel::~EndingLevel()
{
}


void EndingLevel::Start()
{
	//ImageLoad
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter3(Ending)");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}

	SoundLoad();

	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();

	
	CreateActor<SoundAndTextActor>();
	CreateActor<C1_BackGround>();
	CreateActor<EndingPlayButton>();
	//BackCurtain_EndingPtr=CreateActor<BackCurtain_Ending>();
	CreateActor<LevelStateManager>(100);
	MousePtr = CreateActor<Mouse>();

	//Test
	CreateActor<EndingDeleteButton>();
	CreateActor<DeleteArrow>();
}

void EndingLevel::Update(float _DeltaTime)
{
	KeySetting();
	LevelTime += _DeltaTime;
	if (LevelTime > 39.0f)
	{
		BackCurtain_EndingPtr.get()->CurtainOpen();
		static bool CreateBoolS = true;
		if (true == CreateBoolS)
		{
			Play(Sound, "CurtainOpen(Start).wav", 0.1f);
			CreateActor<AlphaCircle>();
			ChangeBGM("Chap01_MusicB.wav");
			CreateBoolS = false;
		}
	}
}

void EndingLevel::LevelChangeStart()
{
	FEffect->FadeOut();
	ChangeBGM("End_IntroMusic.wav");
}

void EndingLevel::LevelChangeEnd()
{
	MainBGM.Stop();
}

void EndingLevel::KeySetting()
{
	if (GameEngineInput::IsDown("TestKey1"))
	{
		GameEngineCore::ChangeLevel("MainMenuLevel");
	}
	if (GameEngineInput::IsDown("TestKey2"))
	{
		GameEngineCore::ChangeLevel("PlaywithinaplayLevel");
	}
	if (GameEngineInput::IsDown("TestKey3"))
	{
		GameEngineCore::ChangeLevel("EndingLevel");
	}
}
