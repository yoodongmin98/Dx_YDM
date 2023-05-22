#include "PrecompileHeader.h"
#include "BoxCroix_FN2.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "ColManager.h"

BoxCroix_FN2::BoxCroix_FN2()
{

}

BoxCroix_FN2::~BoxCroix_FN2()
{
}

void BoxCroix_FN2::Start()
{
	BoxCroixs = Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 405,240,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 405,240,0 });
}

void BoxCroix_FN2::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 3);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		ColManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_FN2::Render(float _Delta)
{

};
