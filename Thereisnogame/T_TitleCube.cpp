#include "PrecompileHeader.h"
#include "T_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


T_TitleCube::T_TitleCube()
{
}

T_TitleCube::~T_TitleCube()
{
}

void T_TitleCube::Start()
{
	T_TitleCubes = Init(T_TitleCubes, "TitleCubeLetter_T.png", { 94,106 }, { -300,140,0 });
	T_TitleCubesCollision = BlockCollisionInit(T_TitleCubesCollision, { 94,106 }, { -300,140,0 });
}

void T_TitleCube::Update(float _DeltaTime)
{
	
}

void T_TitleCube::Render(float _Delta)
{

};


