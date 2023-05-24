#include "PrecompileHeader.h"
#include "PasswordIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"
#include "BoxCroix_FN1.h"
#include "FolderNote_Password.h"

PasswordIcon::PasswordIcon()
{
}

PasswordIcon::~PasswordIcon()
{
}

void PasswordIcon::Start()
{
	PasswordIcons = Init(PasswordIcons, "Document.png", { 75,93 }, {-170,20});
	PasswordIconsCollision = CollisionInit(PasswordIconsCollision, { 75,93 }, { -170,20 });
}

void PasswordIcon::Update(float _DeltaTime)
{
	ManagedCollision(PasswordIconsCollision, 1);
	if (true == ClickCheck(PasswordIconsCollision))
	{
		ColManager::MG->PlusCollisionValue();
		FolderNote_PasswordPtr = GetLevel()->CreateActor<FolderNote_Password>();
		BoxCroix_FN1Ptr = GetLevel()->CreateActor<BoxCroix_FN1>();
	}
	if (nullptr != BoxCroix_FN1Ptr)
	{
		BoxCroixDeathCheck();
	}
}

void PasswordIcon::Render(float _Delta)
{

};

void PasswordIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_FN1Ptr->IsDeath())
	{
		FolderNote_PasswordPtr.get()->Death();
	}
}