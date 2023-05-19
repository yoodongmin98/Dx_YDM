#include "PrecompileHeader.h"
#include "SuperPrivate.h"

//PlatForm
//Core

//Actor

SuperPrivate::SuperPrivate()
{
}

SuperPrivate::~SuperPrivate()
{
}

void SuperPrivate::Start()
{
	//UltraPrivate,Truth2Icon,Panel,Croix Create
	SuperPrivates=Init(SuperPrivates, "Folder.png", { 96,87 }, {-260,20});
	SuperPrivatesCollision = CollisionInit(SuperPrivatesCollision, { 96,87,1 }, { -260,20 });
}

void SuperPrivate::Update(float _DeltaTime)
{
	ManagedCollision(SuperPrivatesCollision, 1);
	if (true == ClickCheck(SuperPrivatesCollision))
	{

	}
}

void SuperPrivate::Render(float _Delta)
{

};
