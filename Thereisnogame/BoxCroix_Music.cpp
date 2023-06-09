#include "PrecompileHeader.h"
#include "BoxCroix_Music.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

#include "LevelStateManager.h"

BoxCroix_Music::BoxCroix_Music()
{

}

BoxCroix_Music::~BoxCroix_Music()
{
}

void BoxCroix_Music::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { -158,110,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { -158,110,0 });
	
}

void BoxCroix_Music::Update(float _DeltaTime)
{
	if (true == ClickCheck(BoxCroixsCollision))
	{
		Play(Sound, "CloseWindow.wav", 0.1f);
		LevelStateManager::MG->MinusCollisionValue();
		BoxCroixsCollision->Death();
		Death();
	}
}

void BoxCroix_Music::Render(float _Delta)
{

};
