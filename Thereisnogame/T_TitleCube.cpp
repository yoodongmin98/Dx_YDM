#include "PrecompileHeader.h"
#include "T_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

T_TitleCube::T_TitleCube()
{
}

T_TitleCube::~T_TitleCube()
{
	
}

void T_TitleCube::Start()
{
	T_TitleCubes = Init(T_TitleCubes, "TitleCubeLetter_T.png", { 94,106 }, { -300,140,0 });
	T_TitleCubesCollision = BlockCollisionInit(T_TitleCubesCollision, { 94,106 }, { -300,140,0 });
}

void T_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		T_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(T_TitleCubesCollision);
}

void T_TitleCube::Render(float _Delta)
{

};

void T_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};



