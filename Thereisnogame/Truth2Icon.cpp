#include "PrecompileHeader.h"
#include "Truth2Icon.h"

//PlatForm
//Core
//Actor



Truth2Icon::Truth2Icon()
{
}

Truth2Icon::~Truth2Icon()
{
}

void Truth2Icon::Start()
{
	//Scale¡∂¡§
	Truth2Icons = Init(Truth2Icons, "Document.png", { 75,93 }, {-70,20});
	Truth2IconsCollision = CollisionInit(Truth2IconsCollision, { 75,93,1 }, { -70,20 });
}

void Truth2Icon::Update(float _DeltaTime)
{
	ManagedCollision(Truth2IconsCollision, 2);
	if (true == ClickCheck(Truth2IconsCollision))
	{

	}
}

void Truth2Icon::Render(float _Delta)
{

};
