#include "PrecompileHeader.h"
#include "BoxCroix_StartRedPanel.h"
#include "ActorTypeEnum.h"


//PlatForm
//Core

#include "LevelStateManager.h"


BoxCroix_StartRedPanel::BoxCroix_StartRedPanel()
{

}

BoxCroix_StartRedPanel::~BoxCroix_StartRedPanel()
{
}

void BoxCroix_StartRedPanel::Start()
{
	float4 Position = { 370,90,0 };
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, Position);
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, Position);
}

void BoxCroix_StartRedPanel::Update(float _DeltaTime)
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

void BoxCroix_StartRedPanel::Render(float _Delta)
{

};
