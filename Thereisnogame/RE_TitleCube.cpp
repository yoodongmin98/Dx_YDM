#include "PrecompileHeader.h"
#include "RE_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


RE_TitleCube::RE_TitleCube()
{
}

RE_TitleCube::~RE_TitleCube()
{
}

void RE_TitleCube::Start()
{
	RE_TitleCubes = Init(RE_TitleCubes, "TitleCubeLetter_E.png", { 94,106 }, { 60,140,0 });
}

void RE_TitleCube::Update(float _DeltaTime)
{

}

void RE_TitleCube::Render(float _Delta)
{

};

