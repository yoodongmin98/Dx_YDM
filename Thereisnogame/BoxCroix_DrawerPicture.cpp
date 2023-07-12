#include "PrecompileHeader.h"
#include "BoxCroix_DrawerPicture.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

//Actor
#include "LevelStateManager.h"


BoxCroix_DrawerPicture::BoxCroix_DrawerPicture()
{

}

BoxCroix_DrawerPicture::~BoxCroix_DrawerPicture()
{
}

void BoxCroix_DrawerPicture::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 317,317,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 317,317,0 });
	Font = FontCreate(Font, 25, "프로그래밍 도구", float4::Down * 250, GetTransform(), 2);

}

void BoxCroix_DrawerPicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		Play(Sound, "CloseWindow.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_DrawerPicture::Render(float _Delta)
{

};
