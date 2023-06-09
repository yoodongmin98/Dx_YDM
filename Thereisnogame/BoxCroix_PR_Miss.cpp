#include "PrecompileHeader.h"
#include "BoxCroix_PR_Miss.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "LevelStateManager.h"

BoxCroix_PR_Miss::BoxCroix_PR_Miss()
{

}

BoxCroix_PR_Miss::~BoxCroix_PR_Miss()
{
}

void BoxCroix_PR_Miss::Start()
{
	BoxCroixs = Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 260,80,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 260,80,0 });
}

void BoxCroix_PR_Miss::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 5);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PR_Miss::Render(float _Delta)
{

};
