#include "PrecompileHeader.h"
#include "PictureFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "DayIcon.h"
#include "DrawerIcon.h"
#include "CodeIcon.h"
#include "PictureFolderPanel.h"
#include "BoxCroix_PictureFolder.h"
#include "LevelStateManager.h"
#include "FolderBackGround.h"

PictureFolder::PictureFolder()
{
}

PictureFolder::~PictureFolder()
{
}

void PictureFolder::Start()
{
	Init(PictureFolders, "Folder.png", { 96,87 }, { -230,-200,0 });
	PictureFoldersCollision = CollisionInit(PictureFoldersCollision, { 96,87,1 }, { -230,-200,0 });
}

void PictureFolder::Update(float _DeltaTime)
{
	ManagedCollision(PictureFoldersCollision, 0);
	if (true == ClickCheck(PictureFoldersCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		FolderBackGroundPtr = GetLevel()->CreateActor<FolderBackGround>();
		PictureFolderPanelPtr=GetLevel()->CreateActor<PictureFolderPanel>();
		DayIconPtr=GetLevel()->CreateActor<DayIcon>();
		DrawerIconPtr=GetLevel()->CreateActor<DrawerIcon>();
		CodeIconPtr=GetLevel()->CreateActor<CodeIcon>();
		BoxCroix_PictureFolderPtr= GetLevel()->CreateActor<BoxCroix_PictureFolder>();
	}
	if (nullptr != BoxCroix_PictureFolderPtr)
	{
		BoxCroixDeathCheck();
	}
}

void PictureFolder::Render(float _Delta)
{

};

void PictureFolder::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PictureFolderPtr->IsDeath())
	{
		FolderBackGroundPtr.get()->Death();
		PictureFolderPanelPtr.get()->Death();
		DayIconPtr.get()->Death();
		DrawerIconPtr.get()->Death();
		CodeIconPtr.get()->Death();
	}
}
