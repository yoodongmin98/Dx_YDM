#include "PrecompileHeader.h"
#include "Private18.h"

//PlatForm
//Core



Private18::Private18()
{
}

Private18::~Private18()
{
}

void Private18::Start()
{
	Init(Private18s, "Folder.png", { 96,87 }, {-140,20});
	Private18sCollision = CollisionInit(Private18sCollision, { 96,87 }, { -140,20 });
}

void Private18::Update(float _DeltaTime)
{
	ManagedCollision(Private18sCollision, 4);
	if (true == ClickCheck(Private18sCollision))
	{
		//Create¾îÂ¼±¸ÀúÂ¼±¸
	}
}

void Private18::Render(float _Delta)
{

};
