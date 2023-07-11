#include "PrecompileHeader.h"
#include "BoxCroix_ClockPanel.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

#include "LevelStateManager.h"


BoxCroix_ClockPanel::BoxCroix_ClockPanel()
{

}

BoxCroix_ClockPanel::~BoxCroix_ClockPanel()
{
}

void BoxCroix_ClockPanel::Start()
{

	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { 150,170,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { 150,170,0 });
}

void BoxCroix_ClockPanel::Update(float _DeltaTime)
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

void BoxCroix_ClockPanel::Render(float _Delta)
{

};
