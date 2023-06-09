#include "PrecompileHeader.h"
#include "UltraPrivate.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "LevelStateManager.h"
#include "GigaPrivate.h"
#include "BoxCroix_PR_Giga.h"
#include "Truth3Icon.h"
#include "PrivatePanel_Giga.h"


UltraPrivate::UltraPrivate()
{
}

UltraPrivate::~UltraPrivate()
{
}

void UltraPrivate::Start()
{
	UltraPrivates = Init(UltraPrivates, "Folder.png", { 96,87 }, {-230,20});
	UltraPrivatesCollision = CollisionInit(UltraPrivatesCollision, { 96,87,1 }, { -230,20 });
}

void UltraPrivate::Update(float _DeltaTime)
{
	ManagedCollision(UltraPrivatesCollision, 2);
	if (true == ClickCheck(UltraPrivatesCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		PrivatePanel_GigaPtr = GetLevel()->CreateActor<PrivatePanel_Giga>();
		GigaprivatePtr = GetLevel()->CreateActor<Gigaprivate>();
		Truth3IconPtr = GetLevel()->CreateActor<Truth3Icon>();
		BoxCroix_PR_GigaPtr = GetLevel()->CreateActor<BoxCroix_PR_Giga>();
	}
	if (nullptr != BoxCroix_PR_GigaPtr)
	{
		BoxCroixDeathCheck();
	}
}

void UltraPrivate::Render(float _Delta)
{

};

void UltraPrivate::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_GigaPtr->IsDeath())
	{
		GigaprivatePtr.get()->Death();
		Truth3IconPtr.get()->Death();
		PrivatePanel_GigaPtr.get()->Death();
	}
}