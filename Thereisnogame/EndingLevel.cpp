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
//Folder


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
	CreateActor<LevelStateManager>(100);
	MousePtr = CreateActor<Mouse>();
}

void EndingLevel::Update(float _DeltaTime)
{
	KeySetting();
}

void EndingLevel::LevelChangeStart()
{
	FEffect->FadeOut();
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
