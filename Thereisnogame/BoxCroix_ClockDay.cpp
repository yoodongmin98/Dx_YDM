#include "PrecompileHeader.h"
#include "BoxCroix_ClockDay.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

#include "LevelStateManager.h"


BoxCroix_ClockDay::BoxCroix_ClockDay()
{

}

BoxCroix_ClockDay::~BoxCroix_ClockDay()
{
}

void BoxCroix_ClockDay::Start()
{

	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { -140,160,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { -140,160,0 });
}

void BoxCroix_ClockDay::Update(float _DeltaTime)
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

void BoxCroix_ClockDay::Render(float _Delta)
{

};
