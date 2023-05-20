#include "PrecompileHeader.h"
#include "USMissIcon.h"

//PlatForm
//Core
//Actor



USMissIcon::USMissIcon()
{
}

USMissIcon::~USMissIcon()
{
}

void USMissIcon::Start()
{
	Init(USMissIcons, "PictureBoard01 #75136.png", { 90,93 }, {-140,10});
	USMissIconsCollision = CollisionInit(USMissIconsCollision, { 90,93 }, { -140,10 });
}

void USMissIcon::Update(float _DeltaTime)
{
	ManagedCollision(USMissIconsCollision, 5);
	if (true == ClickCheck(USMissIconsCollision))
	{

	}
}

void USMissIcon::Render(float _Delta)
{

};
