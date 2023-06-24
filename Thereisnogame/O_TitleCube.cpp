#include "PrecompileHeader.h"
#include "O_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

O_TitleCube::O_TitleCube()
{
}

O_TitleCube::~O_TitleCube()
{
	
}

void O_TitleCube::Start()
{
	O_TitleCubes = Init(O_TitleCubes, "TitleCubeLetter_O.png", { 94,106 }, { -190,10,0 });
	O_TitleCubesCollision = BlockCollisionInit(O_TitleCubesCollision, { 94,106 }, { -190,10,0 });
}

void O_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		O_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(O_TitleCubesCollision);
}

void O_TitleCube::Render(float _Delta)
{

};

void O_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};


