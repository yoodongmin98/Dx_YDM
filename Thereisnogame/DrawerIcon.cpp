#include "PrecompileHeader.h"
#include "DrawerIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "DrawerPicture.h"

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
	}
}

void DrawerIcon::Render(float _Delta)
{

};
