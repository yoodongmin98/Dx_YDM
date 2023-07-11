#include "PrecompileHeader.h"
#include "LockFolder.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core



LockFolder::LockFolder()
{
}

LockFolder::~LockFolder()
{
}

void LockFolder::Start()
{
	Init(LockFolders, "FolderLocked.png", { 96,87 }, { 425,0,0 });
	
	LockFoldersCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::LockFolder);
	LockFoldersCollision->GetTransform()->SetLocalScale({ 96,87 });
	LockFoldersCollision->GetTransform()->SetLocalPosition({ 425,0,0 });

	Font = FontCreate(Font, 28, "접근금지", { 425,-60,0 }, GetTransform(), 2);
}

void LockFolder::Update(float _DeltaTime)
{
	ManagedCollision(LockFoldersCollision, 0);
}

void LockFolder::Render(float _Delta)
{

};
