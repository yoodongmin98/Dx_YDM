#include "PrecompileHeader.h"
#include "ZipWipFolder.h"
#include "ActorTypeEnum.h"
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
	ZipWipFoldersCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::ZipWip);
	ZipWipFoldersCollision->GetTransform()->SetLocalScale({ 87,78,1 });
	ZipWipFoldersCollision->GetTransform()->SetLocalPosition({ -415,0,0 });
}

void ZipWipFolder::Update(float _DeltaTime)
{
	ManagedCollision(ZipWipFoldersCollision, 0);
	if (true == ClickCheck(ZipWipFoldersCollision))
	{
		Play(Sound, "Chap02_ClickZinWip.wav", 0.1f);
	}
}

void ZipWipFolder::Render(float _Delta)
{

};
