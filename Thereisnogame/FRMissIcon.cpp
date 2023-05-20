#include "PrecompileHeader.h"
#include "FRMissIcon.h"

//PlatForm
//Core
//Actor



FRMissIcon::FRMissIcon()
{
}

FRMissIcon::~FRMissIcon()
{
}

void FRMissIcon::Start()
{
	Init(FRMissIcons, "PictureBoard02 #75254.png", { 90,93 }, {20,10});
	FRMissIconsCollision = CollisionInit(FRMissIconsCollision, { 90,93 }, { 20,10 });
}

void FRMissIcon::Update(float _DeltaTime)
{
	ManagedCollision(FRMissIconsCollision, 5);
	if (true == ClickCheck(FRMissIconsCollision))
	{

	}
}

void FRMissIcon::Render(float _Delta)
{

};
