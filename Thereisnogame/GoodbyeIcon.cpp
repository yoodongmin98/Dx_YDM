#include "PrecompileHeader.h"
#include "GoodbyeIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"
#include "FolderNote_GoodBye.h"
#include "BoxCroix_FN1.h"

GoodbyeIcon::GoodbyeIcon()
{
}

GoodbyeIcon::~GoodbyeIcon()
{
}

void GoodbyeIcon::Start()
{
	GoodbyeIcons = Init(GoodbyeIcons, "Document.png", { 75,93 }, {-10,20,0,});
	GoodbyeIconsCollision = CollisionInit(GoodbyeIconsCollision, { 75,93 }, { -10,20,0, });
}

void GoodbyeIcon::Update(float _DeltaTime)
{
	ManagedCollision(GoodbyeIconsCollision, 1);
	if (true == ClickCheck(GoodbyeIconsCollision))
	{
		ColManager::MG->PlusCollisionValue();
		FolderNote_GoodByePtr = GetLevel()->CreateActor<FolderNote_GoodBye>();
		BoxCroix_FN1Ptr = GetLevel()->CreateActor<BoxCroix_FN1>();
	}
	if (nullptr != BoxCroix_FN1Ptr)
	{
		BoxCroixDeathCheck();
	}
}

void GoodbyeIcon::Render(float _Delta)
{

};

void GoodbyeIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_FN1Ptr->IsDeath())
	{
		FolderNote_GoodByePtr.get()->Death();
	}
}