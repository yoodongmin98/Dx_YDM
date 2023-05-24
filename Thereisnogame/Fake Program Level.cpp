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
#include "ColManager.h"

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

//ScreenActor
#include "Cup.h"



FakeProgramLevel::FakeProgramLevel()
{
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

	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	{
		CreateActor<ColManager>(1000);
		CreateActor<C2_BackGround>();
		CreateActor<squirrel>();
		CreateActor<BackSqirrelKey>();
		FolderCreate();
	}
	CreateActor<Cup>(); //Test¿ë
	//CreateActor<AlphaCircle>();
	CreateActor<Mouse>();
}

void FakeProgramLevel::Update(float _DeltaTime)
{
	//Test¿ë
	if (GameEngineInput::IsDown("TestKey3"))
	{
		CreateActor<Chain>();
	}
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