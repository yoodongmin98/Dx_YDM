#include "PrecompileHeader.h"
#include "ZipWipFolder.h"

//PlatForm
//Core



ZipWipFolder::ZipWipFolder()
{
}

ZipWipFolder::~ZipWipFolder()
{
}

void ZipWipFolder::Start()
{
	Init(ZipWipFolders, "ZinWip.png", { 87,78 }, { -415,0,0 });
	ZipWipFoldersCollision = CollisionInit(ZipWipFoldersCollision, { 87,78,1 }, { -415,0,0 });
}

void ZipWipFolder::Update(float _DeltaTime)
{
	ManagedCollision(ZipWipFoldersCollision, 0);
}

void ZipWipFolder::Render(float _Delta)
{

};
