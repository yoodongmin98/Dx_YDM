#include "PrecompileHeader.h"
#include "PrivateFolder.h"

//PlatForm
//Core



PrivateFolder::PrivateFolder()
{
}

PrivateFolder::~PrivateFolder()
{
}

void PrivateFolder::Start()
{
	Init(PrivateFolders, "Folder.png", { 96,87 }, { 225,-200,0 });
	PrivateFoldersCollision = CollisionInit(PrivateFoldersCollision, { 96,87 }, { 225,-200,0 });
}

void PrivateFolder::Update(float _DeltaTime)
{
	if (true == ClickCheck(PrivateFoldersCollision))
	{
		int a = 0;
	}
}

void PrivateFolder::Render(float _Delta)
{

};
