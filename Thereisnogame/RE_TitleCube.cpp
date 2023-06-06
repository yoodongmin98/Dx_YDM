#include "PrecompileHeader.h"
#include "RE_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

RE_TitleCube::RE_TitleCube()
{
}

RE_TitleCube::~RE_TitleCube()
{
	
}

void RE_TitleCube::Start()
{
	RE_TitleCubes = Init(RE_TitleCubes, "TitleCubeLetter_E.png", { 94,106 }, { 60,140,0 });
	RE_TitleCubesCollision = BlockCollisionInit(RE_TitleCubesCollision, { 94,106 }, { 60,140,0 });
}

void RE_TitleCube::Update(float _DeltaTime)
{
	CubeMoveDeathCheck(RE_TitleCubesCollision);
}

void RE_TitleCube::Render(float _Delta)
{

};


