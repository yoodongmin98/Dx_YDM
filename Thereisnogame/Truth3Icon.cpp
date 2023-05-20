#include "PrecompileHeader.h"
#include "Truth3Icon.h"

//PlatForm
//Core
//Actor



Truth3Icon::Truth3Icon()
{
}

Truth3Icon::~Truth3Icon()
{
}

void Truth3Icon::Start()
{
	Init(Truth3Icons, "Document.png", { 75,93 }, { -60,20 });
	Truth3IconsCollision = CollisionInit(Truth3IconsCollision, { 75,93,1 }, { -60,20 });
}

void Truth3Icon::Update(float _DeltaTime)
{
	ManagedCollision(Truth3IconsCollision, 3);
	if (true == ClickCheck(Truth3IconsCollision))
	{
		//Create¾îÂ¼±¸ÀúÂ¼±¸
	}
}

void Truth3Icon::Render(float _Delta)
{

};
