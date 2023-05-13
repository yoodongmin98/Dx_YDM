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
//TrashCan


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
		//Media
		/*CreateActor<MediaPlayer>();
		CreateActor<MediaPlay>();
		CreateActor<MediaPause>();
		CreateActor<MusicFolderPanel>();
		CreateActor<MediaPicture>();

		CreateActor<MusicNote_Archive>();
		CreateActor<MusicNote_Radio>();
		CreateActor<MusicNote_Rain>();
		CreateActor<MusicNote_Walnut>();*/

		//Skite
		/*CreateActor<Skite>();
		CreateActor<SkiteBanner>();
		CreateActor<SkiteCalling>();
		CreateActor<SkiteCallingMissed>();*/

		//Picture
		//CreateActor<PictureFolderPanel>();
		//CreateActor<DayTree>();
		//CreateActor<DayPicture>();
		//CreateActor<DayIcon>();
		//CreateActor<DrawerIcon>();
		//CreateActor<DrawerPicture>();
		//CreateActor<CodeIcon>();
		//CreateActor<CodePicture>();
		
		//Clock
		/*CreateActor<ClockPanel>();
		CreateActor<ClockPaddle1>();
		CreateActor<ClockPaddle2>();
		CreateActor<ClockPaddle3>();
		CreateActor<ClockPaddle4>();
		CreateActor<ClockPaddle5>();
		CreateActor<ClockPaddle6>();
		CreateActor<ClockPaddle7>();
		CreateActor<ClockPaddle8>();
		CreateActor<ClockPaddle9>();
		CreateActor<ClockPaddle0>();*/
		
		//Private Folder
		CreateActor<PrivatePanel>();

	}
		//CreateActor<AlphaCircle>();
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