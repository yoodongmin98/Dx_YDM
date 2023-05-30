#include "PrecompileHeader.h"
#include "R_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


R_TitleCube::R_TitleCube()
{
}

R_TitleCube::~R_TitleCube()
{
}

void R_TitleCube::Start()
{
	R_TitleCubes = Init(R_TitleCubes, "TitleCubeLetter_R.png", { 94,106 }, { -30,150,0 });
}

void R_TitleCube::Update(float _DeltaTime)
{

}

void R_TitleCube::Render(float _Delta)
{

};


