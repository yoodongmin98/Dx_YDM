#include "PrecompileHeader.h"
#include "BoxCroix_Skite.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

#include "LevelStateManager.h"


BoxCroix_Skite::BoxCroix_Skite()
{

}

BoxCroix_Skite::~BoxCroix_Skite()
{
}

void BoxCroix_Skite::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 470,205,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 470,205,0 });

}

void BoxCroix_Skite::Update(float _DeltaTime)
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

void BoxCroix_Skite::Render(float _Delta)
{

};
