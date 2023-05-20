#include "PrecompileHeader.h"
#include "BoxCroix_PR_18.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "ColManager.h"

BoxCroix_PR_18::BoxCroix_PR_18()
{

}

BoxCroix_PR_18::~BoxCroix_PR_18()
{
}

void BoxCroix_PR_18::Start()
{
	BoxCroixs = Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 100,80,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 100,80,0 });
}

void BoxCroix_PR_18::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 4);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		ColManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PR_18::Render(float _Delta)
{

};
