#include "PrecompileHeader.h"
#include "Gigaprivate.h"

//PlatForm
//Core

//Actor
#include "ColManager.h"
#include "Private18.h"


Gigaprivate::Gigaprivate()
{
}

Gigaprivate::~Gigaprivate()
{
}

void Gigaprivate::Start()
{
	Init(Gigaprivates, "Folder.png", { 96,87 }, { -180,20 });
	GigaprivatesCollision = CollisionInit(GigaprivatesCollision, { 96,87,1 }, { -180,20 });
}

void Gigaprivate::Update(float _DeltaTime)
{
	ManagedCollision(GigaprivatesCollision, 3);
	if (true == ClickCheck(GigaprivatesCollision))
	{
		//Create¾îÂ¼±¸ÀúÂ¼±¸
	}
}

void Gigaprivate::Render(float _Delta)
{

};
