#include "PrecompileHeader.h"
#include "BoxCroix_CodePicture.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

//Actor
#include "LevelStateManager.h"


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

	Font = FontCreate(Font, 25, "ID ī��", float4::Down * 250, GetTransform(), 2);
}

void BoxCroix_CodePicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		Play(Sound, "CloseWindow.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_CodePicture::Render(float _Delta)
{

};
