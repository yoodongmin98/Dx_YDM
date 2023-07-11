#include "PrecompileHeader.h"
#include "BoxCroix_TrashCanFolder.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

#include "LevelStateManager.h"


BoxCroix_TrashCanFolder::BoxCroix_TrashCanFolder()
{

}

BoxCroix_TrashCanFolder::~BoxCroix_TrashCanFolder()
{
}

void BoxCroix_TrashCanFolder::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 60,90,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 60,90,0 });

}

void BoxCroix_TrashCanFolder::Update(float _DeltaTime)
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

void BoxCroix_TrashCanFolder::Render(float _Delta)
{

};
