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

//Test용
#include "MediaPlayer.h"
#include "MediaPlay.h"
#include "MediaPause.h"
#include "MusicFolderPanel.h"
#include "BoxCroix.h"
#include "MediaPicture.h"
#include "MusicNote_Archive.h"
#include "MusicNote_Radio.h"
#include "MusicNote_Rain.h"
#include "MusicNote_Walnut.h"

#include "Chain.h"

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

	//백그라운드부터 순서대로(나중에 렌더될수록 가장 앞으로나옴)
	{
		CreateActor<C2_BackGround>();
		CreateActor<squirrel>();
		FolderCreate();
	}
	//미리 Create하지않는 확인용 Actor들
	{
		CreateActor<MediaPlayer>();
		CreateActor<MediaPlay>();
		CreateActor<MediaPause>();
		CreateActor<MusicFolderPanel>();
		CreateActor<MediaPicture>();

		CreateActor<MusicNote_Archive>();
		//CreateActor<MusicNote_Radio>();
		//CreateActor<MusicNote_Rain>();
		CreateActor<MusicNote_Walnut>();

		CreateActor<Chain>();
		
	}
		//CreateActor<AlphaCircle>();
}

void FakeProgramLevel::Update(float _DeltaTime)
{
	
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