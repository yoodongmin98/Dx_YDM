#include "PrecompileHeader.h"
#include "PrivateFolder.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"
#include "SuperPrivate.h"
#include "Truth1Icon.h"
#include "PrivatePanel.h"
#include "BoxCroix_PR_Super.h"

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
	ManagedCollision(PrivateFoldersCollision, 0);
	if (true == ClickCheck(PrivateFoldersCollision))
	{
		ColManager::MG->PlusCollisionValue();
		PrivatePanelPtr = GetLevel()->CreateActor<PrivatePanel>();
		SuperPrivatePtr = GetLevel()->CreateActor<SuperPrivate>();
		Truth1IconPtr = GetLevel()->CreateActor<Truth1Icon>();
		BoxCroix_PR_SuperPtr= GetLevel()->CreateActor<BoxCroix_PR_Super>();
	}
	if (nullptr != BoxCroix_PR_SuperPtr)
	{
		BoxCroixDeathCheck();
	}
}

void PrivateFolder::Render(float _Delta)
{

};

void PrivateFolder::BoxCroixDeathCheck()
{
	//BoxCroix가 죽었다는 상태가 확인이 된다면
	if (true == BoxCroix_PR_SuperPtr->IsDeath())
	{
		PrivatePanelPtr.get()->Death();
		SuperPrivatePtr.get()->Death();
		Truth1IconPtr.get()->Death();
	}
}