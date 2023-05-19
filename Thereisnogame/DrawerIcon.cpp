#include "PrecompileHeader.h"
#include "DrawerIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "DrawerPicture.h"
#include "BoxCroix_DrawerPicture.h"

DrawerIcon::DrawerIcon()
{
}

DrawerIcon::~DrawerIcon()
{
}

void DrawerIcon::Start()
{
	//¾ê°¡ DrawerPicture Create
	DrawerIcons=Init(DrawerIcons, "Picture02a.png", { 90,93 }, { -180,20 });
	DrawerIconsCollision = CollisionInit(DrawerIconsCollision, { 90,93,1}, { -180,20 });
}

void DrawerIcon::Update(float _DeltaTime)
{
	if (true == ClickCheck(DrawerIconsCollision))
	{
		DrawerPicturePtr = GetLevel()->CreateActor<DrawerPicture>();
		BoxCroix_DrawerPicturePtr = GetLevel()->CreateActor<BoxCroix_DrawerPicture>();
	}
	if (nullptr != BoxCroix_DrawerPicturePtr)
	{
		//¾ê ¿Ö ¾ÈµÊ?
		//MusicFoldersCollision->Off();
		BoxCroixDeathCheck();
	}
}

void DrawerIcon::Render(float _Delta)
{

};

void DrawerIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_DrawerPicturePtr->IsDeath())
	{
		DrawerPicturePtr.get()->Death();
	}
}