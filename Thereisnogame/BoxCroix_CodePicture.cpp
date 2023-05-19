#include "PrecompileHeader.h"
#include "BoxCroix_CodePicture.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

//Actor
#include "ColManager.h"


BoxCroix_CodePicture::BoxCroix_CodePicture()
{

}

BoxCroix_CodePicture::~BoxCroix_CodePicture()
{
}

void BoxCroix_CodePicture::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 317,317,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 317,317,0 });

}

void BoxCroix_CodePicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		ColManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_CodePicture::Render(float _Delta)
{

};
