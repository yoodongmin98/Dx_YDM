#include "PrecompileHeader.h"
#include "Truth1Icon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
 
 
//Actor
#include "LevelStateManager.h"
#include "FolderNote.h"
#include "BoxCroix_FN1.h"



Truth1Icon::Truth1Icon()
{
}

Truth1Icon::~Truth1Icon()
{
}

void Truth1Icon::Start()
{
	//ScaleÁ¶Á¤
	Truth1Icons=Init(Truth1Icons, "Document.png", { 75,93 }, {-100,20});
	Truth1IconsCollision = CollisionInit(Truth1IconsCollision, { 75,93,1 }, { -100,20 });
}

void Truth1Icon::Update(float _DeltaTime)
{
	ManagedCollision(Truth1IconsCollision, 1);
	if (true == ClickCheck(Truth1IconsCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		FolderNotePtr = GetLevel()->CreateActor<FolderNote>();
		BoxCroix_FN1Ptr = GetLevel()->CreateActor<BoxCroix_FN1>();
	}
	if (nullptr != BoxCroix_FN1Ptr)
	{
		BoxCroixDeathCheck();
	}
}

void Truth1Icon::Render(float _Delta)
{

};

void Truth1Icon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_FN1Ptr->IsDeath())
	{
		FolderNotePtr.get()->Death();
	}
}