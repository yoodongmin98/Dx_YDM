#include "PrecompileHeader.h"
#include "M_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


M_TitleCube::M_TitleCube()
{
}

M_TitleCube::~M_TitleCube()
{
}

void M_TitleCube::Start()
{
	M_TitleCubes = Init(M_TitleCubes, "TitleCubeLetter_M.png", { 94,106 }, { 120,0,0 });
	M_TitleCubesCollision = CollisionInit(M_TitleCubesCollision, { 94,106 }, { 120,0,0 });
}

void M_TitleCube::Update(float _DeltaTime)
{

}

void M_TitleCube::Render(float _Delta)
{

};


