#include "PrecompileHeader.h"
#include "Ball_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


Ball_TitleCube::Ball_TitleCube()
{
}

Ball_TitleCube::~Ball_TitleCube()
{
}

void Ball_TitleCube::Start()
{
	Ball_TitleCubes = Init(Ball_TitleCubes, "TitleCube_Ball.png", { 44,58 }, { 300,-30,0 });
}

void Ball_TitleCube::Update(float _DeltaTime)
{

}

void Ball_TitleCube::Render(float _Delta)
{

};


