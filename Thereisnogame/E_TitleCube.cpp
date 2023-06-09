#include "PrecompileHeader.h"
#include "E_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

E_TitleCube::E_TitleCube()
{
}

E_TitleCube::~E_TitleCube()
{
	
}

void E_TitleCube::Start()
{
	E_TitleCubes = Init(E_TitleCubes, "TitleCubeLetter_E.png", { 94,106 }, { -120,140,0 });
	E_TitleCubesCollision = BlockCollisionInit(E_TitleCubesCollision, { 94,106 }, { -120,140,0 });
}

void E_TitleCube::Update(float _DeltaTime)
{
	CubeMoveDeathCheck(E_TitleCubesCollision);
}

void E_TitleCube::Render(float _Delta)
{

};


