#include "PrecompileHeader.h"
#include "MusicFolder.h"

//PlatForm
//Core



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
		//CreateActor<>();
	}
}

void MusicFolder::Render(float _Delta)
{

};
