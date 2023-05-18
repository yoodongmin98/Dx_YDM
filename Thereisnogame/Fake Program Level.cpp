#include "PrecompileHeader.h"
#include "Fake Program Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>


#include "Mouse.h"
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

//Test��
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
//Skite
#include "Skite.h"
#include "SkiteBanner.h"
#include "SkiteCalling.h"
#include "SkiteCallingMissed.h"
//Pictures
#include "PictureFolderPanel.h"
#include "DayTree.h"
#include "DayPicture.h"
#include "DayIcon.h"
#include "DrawerIcon.h"
#include "DrawerPicture.h"
#include "CodeIcon.h"
#include "CodePicture.h"
//Clock
#include "ClockPanel.h"
#include "ClockPaddle0.h"
#include "ClockPaddle1.h"
#include "ClockPaddle2.h"
#include "ClockPaddle3.h"
#include "ClockPaddle4.h"
#include "ClockPaddle5.h"
#include "ClockPaddle6.h"
#include "ClockPaddle7.h"
#include "ClockPaddle8.h"
#include "ClockPaddle9.h"
//Private
#include "PrivatePanel.h"
#include "FolderNote.h"
//TrashCan
//ScreenActor
#include "Cup.h"


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

	{
		CreateActor<C2_BackGround>();
		CreateActor<squirrel>();
		FolderCreate();
	}
	CreateActor<Cup>(); //Test��
	//CreateActor<AlphaCircle>();
	CreateActor<Mouse>();
}

void FakeProgramLevel::Update(float _DeltaTime)
{
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