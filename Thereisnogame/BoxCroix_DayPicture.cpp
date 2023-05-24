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

}

void BoxCroix_DayPicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_DayPicture::Render(float _Delta)
{

};
