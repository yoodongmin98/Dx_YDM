#include "PrecompileHeader.h"
#include "BoxCroix_PR_Ultra.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "LevelStateManager.h"

BoxCroix_PR_Ultra::BoxCroix_PR_Ultra()
{

}

BoxCroix_PR_Ultra::~BoxCroix_PR_Ultra()
{
}

void BoxCroix_PR_Ultra::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 10,80,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 10,80,0 });
}

void BoxCroix_PR_Ultra::Update(float _DeltaTime)
{
	ManagedCollision(BoxCroixsCollision, 2);
	if (true == ClickCheck(BoxCroixsCollision))
	{
		Play(Sound, "CloseWindow.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_PR_Ultra::Render(float _Delta)
{

};
