#include "PrecompileHeader.h"
#include "MusicFolder.h"
#include "ActorTypeEnum.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "MusicFolderPanel.h"
#include "MusicNote_Archive.h"
#include "MusicNote_Radio.h"
#include "MusicNote_Rain.h"
#include "MusicNote_Walnut.h"
#include "MediaPlayer.h"
#include "MediaPause.h"
#include "MediaPlay.h"
#include "MediaPicture.h"
#include "BoxCroix_Music.h"
#include "LevelStateManager.h"
#include "FolderBackGround.h"
#include "Fake Program Level.h"

MusicFolder::MusicFolder()
{
}

MusicFolder::~MusicFolder()
{
}

void MusicFolder::Start()
{
	Init(MusicFolders, "Folder.png", { 96,87 }, { -425,-200,0 });
	MusicFoldersCollision = CollisionInit(MusicFoldersCollision, { 96,87,1 }, { -425,-200,0 });
	Font = FontCreate(Font, 28, "À½¾Ç", { -425,-260,0 }, GetTransform(), 2);
}

void MusicFolder::Update(float _DeltaTime)
{
	ManagedCollision(MusicFoldersCollision, 0);
	if (true == ClickCheck(MusicFoldersCollision))
	{
		Play(Sound, "OpenWindow.wav", 0.1f);
		FakeProgramLevel::FP->ChangeBGM("Chap02_NutCrackerMusic.wav");
		LevelStateManager::MG->PlusCollisionValue();
		LevelStateManager::MG->SetIsRainfalse();
		LevelStateManager::MG->SetIsWalNuttrue();
		FolderBackGroundPtr= GetLevel()->CreateActor<FolderBackGround>();
		MusicFolderPanelPtr=GetLevel()->CreateActor<MusicFolderPanel>();
		MediaPlayerPtr=GetLevel()->CreateActor<MediaPlayer>();
		MusicNote_ArchivePtr=GetLevel()->CreateActor<MusicNote_Archive>();
		MusicNote_RadioPtr=GetLevel()->CreateActor<MusicNote_Radio>();
		MusicNote_RainPtr=GetLevel()->CreateActor<MusicNote_Rain>();
		MusicNote_WalnutPtr=GetLevel()->CreateActor<MusicNote_Walnut>();
		MediaPlayPtr=GetLevel()->CreateActor<MediaPlay>();
		MediaPausePtr=GetLevel()->CreateActor<MediaPause>();
		MediaPicturePtr=GetLevel()->CreateActor<MediaPicture>();
		BoxCroixPtr=GetLevel()->CreateActor<BoxCroix_Music>();
	}
	if (nullptr != BoxCroixPtr)
	{
		BoxCroixDeathCheck();
	}
}

void MusicFolder::Render(float _Delta)
{

};

void MusicFolder::BoxCroixDeathCheck()
{
	if (true==BoxCroixPtr->IsDeath())
	{
		MusicFolderPanelPtr.get()->Death();
		MusicNote_ArchivePtr.get()->Death();
		MusicNote_RadioPtr.get()->Death();
		MusicNote_RainPtr.get()->Death();
		MusicNote_WalnutPtr.get()->Death();
		MediaPlayerPtr.get()->Death();
		MediaPlayPtr.get()->Death();
		MediaPausePtr.get()->Death();
		MediaPicturePtr.get()->Death();
		FolderBackGroundPtr.get()->Death();
	}
}