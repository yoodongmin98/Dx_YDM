#include "PrecompileHeader.h"
#include "Fake Program Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>

//Actor
#include "AlphaCircle.h"
#include "C2_BackGround.h"
#include "squirrel.h"
#include "BackSqirrelKey.h"
#include "Mouse.h"
#include "Chain.h"
#include "LevelStateManager.h"
#include "FadeEffect.h"
//Folder
#include "SkiteFolder.h"
#include "ZipWipFolder.h"
#include "MusicFolder.h"
#include "PictureFolder.h"
#include "PrivateFolder.h"
#include "LockFolder.h"
#include "ClockFolder.h"
#include "TrashcanFolder.h"
#include "TrashcanTop.h"
#include "StartRedPanel.h"
#include "BoxCroix_StartRedPanel.h"
#include "FolderBackGround.h"
#include "Chap2StartTextActor.h"

FakeProgramLevel* FakeProgramLevel::FP;

FakeProgramLevel::FakeProgramLevel()
{
	FP = this;
}

FakeProgramLevel::~FakeProgramLevel()
{
}


void FakeProgramLevel::Start()
{
	//ImageLoad
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter2(window)");

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

	{
		CreateActor<LevelStateManager>(100);
		CreateActor<C2_BackGround>();
		CreateActor<squirrel>();
		CreateActor<BackSqirrelKey>();
		FolderCreate();
	}
	MousePtr=CreateActor<Mouse>();
	CreateActor<AlphaCircle>();
}

void FakeProgramLevel::Update(float _DeltaTime)
{
	KeySetting();
	StartFunctions(_DeltaTime);

	if (nullptr != BoxCroix_StartRedPanelPtr)
	{
		if (true == BoxCroix_StartRedPanelPtr->IsDeath())
		{
			StartRedPanelPtr.get()->Death();
			FolderBackGroundPtr.get()->Death();
			static bool ChainCreateBool = true;
			if (true == ChainCreateBool)
			{
				ChainPtr=CreateActor<Chain>();
				ChainPtr.get()->SetChainLiveTime(10);
				CreateActor<Chap2StartTextActor>();
				ChainCreateBool = false;
			}
		}
	}
}

void FakeProgramLevel::LevelChangeStart()
{
	FEffect->FadeOut();
	ReSetBGM();
}

void FakeProgramLevel::FolderCreate()
{
	CreateActor<SkiteFolder>();
	CreateActor<ZipWipFolder>();
	CreateActor<MusicFolder>();
	CreateActor<PictureFolder>();
	CreateActor<PrivateFolder>();
	CreateActor<LockFolder>();
	CreateActor<ClockFolder>();
	CreateActor<TrashcanFolder>();
	CreateActor<TrashcanTop>();
}

bool StartCreateActorBool = true;
void FakeProgramLevel::StartFunctions(float _DeltaTime)
{
	StartTime += _DeltaTime;
	if (StartTime > 1.0f &&true== StartCreateActorBool)
	{
		StartCreateActorBool = false;
		LevelStateManager::MG->PlusCollisionValue();
		FolderBackGroundPtr=CreateActor<FolderBackGround>();
		StartRedPanelPtr=CreateActor<StartRedPanel>();
		BoxCroix_StartRedPanelPtr=CreateActor<BoxCroix_StartRedPanel>();
	}
}

void FakeProgramLevel::KeySetting()
{
	if (GameEngineInput::IsDown("TestKey1"))
	{
		GameEngineCore::ChangeLevel("MainMenuLevel");
	}
	if (GameEngineInput::IsDown("TestKey2"))
	{
		GameEngineCore::ChangeLevel("PlaywithinaplayLevel");
	}
	if (GameEngineInput::IsDown("TestKey4"))
	{
		GameEngineCore::ChangeLevel("EndingLevel");
	}
	if (GameEngineInput::IsDown("LeftMouse")
		&& false == LevelStateManager::MG->GetIsProgress())
	{
		Play(Sound, "MouseClick.wav", 0.1f);
	}
}
