#include "PrecompileHeader.h"
#include "H_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

H_TitleCube::H_TitleCube()
{
}

H_TitleCube::~H_TitleCube()
{
	
}

void H_TitleCube::Start()
{
	H_TitleCubes = Init(H_TitleCubes, "TitleCubeLetter_H.png", { 94,106 }, { -210,150,0 });
	H_TitleCubesCollision = BlockCollisionInit(H_TitleCubesCollision, { 94,106 }, { -210,150,0 });
}

void H_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		H_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(H_TitleCubesCollision);
}

void H_TitleCube::Render(float _Delta)
{

};

void H_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};


