#include "PrecompileHeader.h"
#include "N_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

N_TitleCube::N_TitleCube()
{
}

N_TitleCube::~N_TitleCube()
{
	
}

void N_TitleCube::Start()
{
	N_TitleCubes = Init(N_TitleCubes, "TitleCubeLetter_N.png", { 94,106 }, { -280,0,0 });
	N_TitleCubesCollision = BlockCollisionInit(N_TitleCubesCollision, { 94,106 }, { -280,0,0 });
}

void N_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		N_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(N_TitleCubesCollision);
}

void N_TitleCube::Render(float _Delta)
{

};

void N_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};



