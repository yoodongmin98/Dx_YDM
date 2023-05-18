#include "PrecompileHeader.h"
#include "ClockFolder.h"

//PlatForm
//Core



ClockFolder::ClockFolder()
{
}

ClockFolder::~ClockFolder()
{
}

void ClockFolder::Start()
{
	Init(ClockFolders, "HourOs_Night00.png", { 102,97 }, { 420,200,0 });
	ClockFoldersCollision = CollisionInit(ClockFoldersCollision, { 102,97 }, { 420,200,0 });
}

void ClockFolder::Update(float _DeltaTime)
{
	if (true == ClickCheck(ClockFoldersCollision))
	{
		int a = 0;
	}
}

void ClockFolder::Render(float _Delta)
{

};
