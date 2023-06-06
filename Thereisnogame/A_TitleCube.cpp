#include "PrecompileHeader.h"
#include "A_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

A_TitleCube::A_TitleCube()
{
}

A_TitleCube::~A_TitleCube()
{
	
}

void A_TitleCube::Start()
{
	A_TitleCubes = Init(A_TitleCubes, "TitleCubeLetter_A.png", { 94,106 }, { 30,10,0 });
	A_TitleCubesCollision = BlockCollisionInit(A_TitleCubesCollision, { 94,106 }, { 30,10,0 });
}

void A_TitleCube::Update(float _DeltaTime)
{
	CubeMoveDeathCheck(A_TitleCubesCollision);
}

void A_TitleCube::Render(float _Delta)
{

};


