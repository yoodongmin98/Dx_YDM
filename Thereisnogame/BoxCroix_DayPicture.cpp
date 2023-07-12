#include "PrecompileHeader.h"
#include "BoxCroix_DayPicture.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

#include "LevelStateManager.h"



BoxCroix_DayPicture::BoxCroix_DayPicture()
{

}

BoxCroix_DayPicture::~BoxCroix_DayPicture()
{
}

void BoxCroix_DayPicture::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 317,317,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 317,317,0 });
	Font = FontCreate(Font, 25, "¹Ì·¡ÀÇ ÇìÀÌÁñ³Ó ³ª¹«", float4::Down * 250, GetTransform(), 2);

}

void BoxCroix_DayPicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		Play(Sound, "CloseWindow.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_DayPicture::Render(float _Delta)
{

};
