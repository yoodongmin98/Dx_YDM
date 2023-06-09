#include "PrecompileHeader.h"
#include "Truth3Icon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "FolderNote3.h"
#include "BoxCroix_FN3.h"


Truth3Icon::Truth3Icon()
{
}

Truth3Icon::~Truth3Icon()
{
}

void Truth3Icon::Start()
{
	Init(Truth3Icons, "Document.png", { 75,93 }, { -60,20 });
	Truth3IconsCollision = CollisionInit(Truth3IconsCollision, { 75,93,1 }, { -60,20 });
}

void Truth3Icon::Update(float _DeltaTime)
{
	ManagedCollision(Truth3IconsCollision, 3);
	if (true == ClickCheck(Truth3IconsCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		FolderNotePtr = GetLevel()->CreateActor<FolderNote3>();
		BoxCroix_FN3Ptr = GetLevel()->CreateActor<BoxCroix_FN3>();
	}
	if (nullptr != BoxCroix_FN3Ptr)
	{
		BoxCroixDeathCheck();
	}
}

void Truth3Icon::Render(float _Delta)
{

};

void Truth3Icon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_FN3Ptr->IsDeath())
	{
		FolderNotePtr.get()->Death();
	}
}