#include "PrecompileHeader.h"
#include "SkiteFolder.h"

//PlatForm
//Core



SkiteFolder::SkiteFolder()
{
}

SkiteFolder::~SkiteFolder()
{
}

void SkiteFolder::Start()
{
	Init(SkiteFolders, "Skite.png", { 103,102 }, { -420,200,0 });
	SkiteFoldersCollision = CollisionInit(SkiteFoldersCollision, { 103,102 }, { -420,200,0 });
}

void SkiteFolder::Update(float _DeltaTime)
{
	if (true == ClickCheck(SkiteFoldersCollision))
	{
		int a = 0;
	}
}

void SkiteFolder::Render(float _Delta)
{

};
