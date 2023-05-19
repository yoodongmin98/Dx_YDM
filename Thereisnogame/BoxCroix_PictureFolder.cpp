#include "PrecompileHeader.h"
#include "BoxCroix_PictureFolder.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core



BoxCroix_PictureFolder::BoxCroix_PictureFolder()
{

}

BoxCroix_PictureFolder::~BoxCroix_PictureFolder()
{
}

void BoxCroix_PictureFolder::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 63,95,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 63,95,0 });

}

void BoxCroix_PictureFolder::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PictureFolder::Render(float _Delta)
{

};
