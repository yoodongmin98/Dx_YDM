#include "PrecompileHeader.h"
#include "PictureFolder.h"

//PlatForm
//Core

//Actor


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
		int a = 0;
	}
}

void PictureFolder::Render(float _Delta)
{

};
