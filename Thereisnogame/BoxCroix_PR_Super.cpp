#include "PrecompileHeader.h"
#include "BoxCroix_PR_Super.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "LevelStateManager.h"

BoxCroix_PR_Super::BoxCroix_PR_Super()
{

}

BoxCroix_PR_Super::~BoxCroix_PR_Super()
{
}

void BoxCroix_PR_Super::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { -20,80,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { -20,80,0 });
}

void BoxCroix_PR_Super::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 1);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		Play(Sound, "CloseWindow.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PR_Super::Render(float _Delta)
{

};
