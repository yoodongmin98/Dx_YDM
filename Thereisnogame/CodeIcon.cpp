#include "PrecompileHeader.h"
#include "CodeIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "CodePicture.h"
#include "BoxCroix_CodePicture.h"

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
	if (true == ClickCheck(CodeIconsCollision))
	{
		CodePicturePtr = GetLevel()->CreateActor<CodePicture>();
		BoxCroix_CodePicturePtr= GetLevel()->CreateActor<BoxCroix_CodePicture>();
	}
	if (nullptr != BoxCroix_CodePicturePtr)
	{
		//¾ê ¿Ö ¾ÈµÊ?
		//MusicFoldersCollision->Off();
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
	}
}