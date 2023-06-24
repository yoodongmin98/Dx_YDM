#include "PrecompileHeader.h"
#include "I_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

I_TitleCube::I_TitleCube()
{
}

I_TitleCube::~I_TitleCube()
{
	
}

void I_TitleCube::Start()
{
	I_TitleCubes = Init(I_TitleCubes, "TitleCubeLetter_I.png", { 94,106 }, { 190,150,0 });
	I_TitleCubesCollision = BlockCollisionInit(I_TitleCubesCollision, { 94,106 }, { 190,150,0 });
}

void I_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		I_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(I_TitleCubesCollision);
}

void I_TitleCube::Render(float _Delta)
{

};

void I_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};



