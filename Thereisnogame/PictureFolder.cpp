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
	if (true == ClickCheck(PictureFoldersCollision))
	{
		PictureFolderPanelPtr=GetLevel()->CreateActor<PictureFolderPanel>();
		DayIconPtr=GetLevel()->CreateActor<DayIcon>();
		DrawerIconPtr=GetLevel()->CreateActor<DrawerIcon>();
		CodeIconPtr=GetLevel()->CreateActor<CodeIcon>();
		BoxCroix_PictureFolderPtr= GetLevel()->CreateActor<BoxCroix_PictureFolder>();
	}
	if (nullptr != BoxCroix_PictureFolderPtr)
	{
		//얘 왜 안됨?
		//MusicFoldersCollision->Off();
		BoxCroixDeathCheck();
	}
}

void PictureFolder::Render(float _Delta)
{

};

void PictureFolder::BoxCroixDeathCheck()
{
	//BoxCroix가 죽었다는 상태가 확인이 된다면
	if (true == BoxCroix_PictureFolderPtr->IsDeath())
	{
		PictureFolderPanelPtr.get()->Death();
		DayIconPtr.get()->Death();
		DrawerIconPtr.get()->Death();
		CodeIconPtr.get()->Death();
	}
}
