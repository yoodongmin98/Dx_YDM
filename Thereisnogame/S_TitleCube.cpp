#include "PrecompileHeader.h"
#include "S_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


S_TitleCube::S_TitleCube()
{
}

S_TitleCube::~S_TitleCube()
{
}

void S_TitleCube::Start()
{
	S_TitleCubes = Init(S_TitleCubes, "TitleCubeLetter_S.png", { 94,106 }, { 280,160,0 });
	S_TitleCubesCollision = BlockCollisionInit(S_TitleCubesCollision, { 94,106 }, { 280,160,0 });
}

void S_TitleCube::Update(float _DeltaTime)
{
	CubeMoveDeathCheck(S_TitleCubesCollision);
}

void S_TitleCube::Render(float _Delta)
{

};


