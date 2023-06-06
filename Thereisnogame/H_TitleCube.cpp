#include "PrecompileHeader.h"
#include "H_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


H_TitleCube::H_TitleCube()
{
}

H_TitleCube::~H_TitleCube()
{
}

void H_TitleCube::Start()
{
	H_TitleCubes = Init(H_TitleCubes, "TitleCubeLetter_H.png", { 94,106 }, { -210,150,0 });
	H_TitleCubesCollision = BlockCollisionInit(H_TitleCubesCollision, { 94,106 }, { -210,150,0 });
}

void H_TitleCube::Update(float _DeltaTime)
{
	CubeMoveDeathCheck(H_TitleCubesCollision);
}

void H_TitleCube::Render(float _Delta)
{

};


