#include "PrecompileHeader.h"
#include "MusicFolder.h"
#include "ActorTypeEnum.h"

//Base
//PlatForm
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
#include "BoxCroix.h"


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
}

void MusicFolder::Update(float _DeltaTime)
{
	if (true == ClickCheck(MusicFoldersCollision))
	{
		GetLevel()->CreateActor<MusicFolderPanel>();
		GetLevel()->CreateActor<MusicNote_Archive>();
		GetLevel()->CreateActor<MusicNote_Radio>();
		GetLevel()->CreateActor<MusicNote_Rain>();
		GetLevel()->CreateActor<MusicNote_Walnut>();
		GetLevel()->CreateActor<MediaPlayer>();
		GetLevel()->CreateActor<MediaPlay>();
		GetLevel()->CreateActor<MediaPause>();
		GetLevel()->CreateActor<MediaPicture>();
		GetLevel()->CreateActor<BoxCroix>();
	}
	
	
}

void MusicFolder::Render(float _Delta)
{

};
