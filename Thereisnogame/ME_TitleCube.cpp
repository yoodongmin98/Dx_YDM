#include "PrecompileHeader.h"
#include "ME_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

ME_TitleCube::ME_TitleCube()
{
}

ME_TitleCube::~ME_TitleCube()
{
	
}

void ME_TitleCube::Start()
{
	ME_TitleCubes = Init(ME_TitleCubes, "TitleCubeLetter_E.png", { 94,106 }, { 210,10,0 });
	ME_TitleCubesCollision = BlockCollisionInit(ME_TitleCubesCollision, { 94,106 }, { 210,10,0 });
}

void ME_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		ME_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(ME_TitleCubesCollision);
}

void ME_TitleCube::Render(float _Delta)
{

};

void ME_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};



