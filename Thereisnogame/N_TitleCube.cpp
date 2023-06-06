#include "PrecompileHeader.h"
#include "N_TitleCube.h"

//Base
//PlatForm
//Core


//Actor


N_TitleCube::N_TitleCube()
{
}

N_TitleCube::~N_TitleCube()
{
}

void N_TitleCube::Start()
{
	N_TitleCubes = Init(N_TitleCubes, "TitleCubeLetter_N.png", { 94,106 }, { -280,0,0 });
	N_TitleCubesCollision = CollisionInit(N_TitleCubesCollision, { 94,106 }, { -280,0,0 });
}

void N_TitleCube::Update(float _DeltaTime)
{

}

void N_TitleCube::Render(float _Delta)
{

};


