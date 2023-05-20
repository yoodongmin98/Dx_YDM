#include "PrecompileHeader.h"
#include "JPMissIcon.h"

//PlatForm
//Core
//Actor



JPMissIcon::JPMissIcon()
{
}

JPMissIcon::~JPMissIcon()
{
}

void JPMissIcon::Start()
{
	Init(JPMissIcons, "PictureBoard03.png", { 90,93 }, {180,10});
	JPMissIconsCollision = CollisionInit(JPMissIconsCollision, { 90,93 }, { 180,10 });
}

void JPMissIcon::Update(float _DeltaTime)
{
	ManagedCollision(JPMissIconsCollision, 5);
	if (true == ClickCheck(JPMissIconsCollision))
	{

	}
}

void JPMissIcon::Render(float _Delta)
{

};
