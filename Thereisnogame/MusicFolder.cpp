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


MusicFolder::MusicFolder()
{
}

MusicFolder::~MusicFolder()
{
}

void MusicFolder::Start()
{
	Init(MusicFolders, "Folder.png", { 96,87 }, { -425,-200,0 });
	MusicFoldersCollision = CollisionInit(MusicFoldersCollision, { 96,87 }, { -425,-200,0 });
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
		BoxCroixsCollision=BoxCroixCreate(Croix, { -158,110,-1 });

		//여기하고있다
		if (BoxCroixsCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
		{
			int a = 0;
		}
	}
	
	
}

void MusicFolder::Render(float _Delta)
{

};
