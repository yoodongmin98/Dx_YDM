#include "PrecompileHeader.h"
#include "BoxCroix_FN3.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "LevelStateManager.h"

BoxCroix_FN3::BoxCroix_FN3()
{

}

BoxCroix_FN3::~BoxCroix_FN3()
{
}

void BoxCroix_FN3::Start()
{
	BoxCroixs = Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 405,240,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 405,240,0 });
}

void BoxCroix_FN3::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 4);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_FN3::Render(float _Delta)
{

};
