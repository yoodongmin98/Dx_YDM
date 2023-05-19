#include "PrecompileHeader.h"
#include "CodeIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "CodePicture.h"
#include "BoxCroix_CodePicture.h"
#include "ColManager.h"
#include "RightRotate.h"
#include "LeftRotate.h"

CodeIcon::CodeIcon()
{
}

CodeIcon::~CodeIcon()
{
}

void CodeIcon::Start()
{
	//¾ê°¡CodePicture Create
	CodeIcons=Init(CodeIcons, "Picture03.png", { 90,93 }, {-20,20});
	CodeIconsCollision = CollisionInit(CodeIconsCollision, { 90,93,1 }, { -20,20 });
}

void CodeIcon::Update(float _DeltaTime)
{
	ManagedCollision(CodeIconsCollision, 1);
	if (true == ClickCheck(CodeIconsCollision))
	{
		ColManager::MG->PlusCollisionValue();
		CodePicturePtr = GetLevel()->CreateActor<CodePicture>();
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
	}
}