#include "PrecompileHeader.h"
#include "ME_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


ME_TitleCube::ME_TitleCube()
{
}

ME_TitleCube::~ME_TitleCube()
{
}

void ME_TitleCube::Start()
{
	ME_TitleCubes = Init(ME_TitleCubes, "TitleCubeLetter_E.png", { 94,106 }, { 210,10,0 });
}

void ME_TitleCube::Update(float _DeltaTime)
{

}

void ME_TitleCube::Render(float _Delta)
{

};


