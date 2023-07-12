#include "PrecompileHeader.h"
#include "CodeIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "CodePicture.h"
#include "BoxCroix_CodePicture.h"
#include "LevelStateManager.h"
#include "RightRotate.h"
#include "LeftRotate.h"
#include "PurpleBox.h"

CodeIcon::CodeIcon()
{
}

CodeIcon::~CodeIcon()
{
}

void CodeIcon::Start()
{
	CodeIcons=Init(CodeIcons, "Picture03.png", { 90,93 }, {-20,20});
	CodeIconsCollision = CollisionInit(CodeIconsCollision, { 90,93,1 }, { -20,20 });
	Font = FontCreate(Font, 25, "ÀÌ¹ÌÁö\n03", { -20,-40 }, GetTransform(), 2);
}

void CodeIcon::Update(float _DeltaTime)
{
	ManagedCollision(CodeIconsCollision, 1);
	if (true == ClickCheck(CodeIconsCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		CodePicturePtr = GetLevel()->CreateActor<CodePicture>();
		PurpleBoxPtr = GetLevel()->CreateActor<PurpleBox>();
		BoxCroix_CodePicturePtr= GetLevel()->CreateActor<BoxCroix_CodePicture>();
		LeftRotatePtr = GetLevel()->CreateActor<LeftRotate>();
		RightRotatePtr = GetLevel()->CreateActor<RightRotate>();
	}
	if (nullptr != BoxCroix_CodePicturePtr)
	{
		BoxCroixDeathCheck();
	}
}

void CodeIcon::Render(float _Delta)
{

};

void CodeIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_CodePicturePtr->IsDeath())
	{
		CodePicturePtr.get()->Death();
		LeftRotatePtr.get()->Death();
		RightRotatePtr.get()->Death();
		PurpleBoxPtr.get()->Death();
	}
}