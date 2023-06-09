#include "PrecompileHeader.h"
#include "BoxCroix_PR_Giga.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "LevelStateManager.h"

BoxCroix_PR_Giga::BoxCroix_PR_Giga()
{

}

BoxCroix_PR_Giga::~BoxCroix_PR_Giga()
{
}

void BoxCroix_PR_Giga::Start()
{
	BoxCroixs=Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 40,80,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 40,80,0 });
}

void BoxCroix_PR_Giga::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 3);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PR_Giga::Render(float _Delta)
{

};
