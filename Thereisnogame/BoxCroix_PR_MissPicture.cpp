#include "PrecompileHeader.h"
#include "BoxCroix_PR_MissPicture.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "ColManager.h"

BoxCroix_PR_MissPicture::BoxCroix_PR_MissPicture()
{

}

BoxCroix_PR_MissPicture::~BoxCroix_PR_MissPicture()
{
}

void BoxCroix_PR_MissPicture::Start()
{
	BoxCroixs = Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 317,317,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 317,317,0 });
}

void BoxCroix_PR_MissPicture::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 6);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		ColManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PR_MissPicture::Render(float _Delta)
{

};
