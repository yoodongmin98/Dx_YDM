#include "PrecompileHeader.h"
#include "Truth2Icon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "FolderNote2.h"
#include "BoxCroix_FN2.h"


Truth2Icon::Truth2Icon()
{
}

Truth2Icon::~Truth2Icon()
{
}

void Truth2Icon::Start()
{
	Truth2Icons = Init(Truth2Icons, "Document.png", { 75,93 }, {-80,20});
	Truth2IconsCollision = CollisionInit(Truth2IconsCollision, { 75,93,1 }, { -80,20 });
}

void Truth2Icon::Update(float _DeltaTime)
{
	ManagedCollision(Truth2IconsCollision, 2);
	if (true == ClickCheck(Truth2IconsCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		FolderNotePtr = GetLevel()->CreateActor<FolderNote2>();
		BoxCroix_FN2Ptr = GetLevel()->CreateActor<BoxCroix_FN2>();
	}
	if (nullptr != BoxCroix_FN2Ptr)
	{
		BoxCroixDeathCheck();
	}
}

void Truth2Icon::Render(float _Delta)
{

};

void Truth2Icon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_FN2Ptr->IsDeath())
	{
		FolderNotePtr.get()->Death();
	}
}