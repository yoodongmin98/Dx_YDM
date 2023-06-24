#include "PrecompileHeader.h"
#include "G_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "Play within a play Level.h"

G_TitleCube::G_TitleCube()
{
}

G_TitleCube::~G_TitleCube()
{
	
}

void G_TitleCube::Start()
{
	G_TitleCubes = Init(G_TitleCubes, "TitleCubeLetter_G.png", { 94,106 }, { -60,0,0 });
	G_TitleCubesCollision = BlockCollisionInit(G_TitleCubesCollision, { 94,106 }, { -60,0,0 });
}

void G_TitleCube::Update(float _DeltaTime)
{
	if (true == DeathCheck)
	{
		G_TitleCubesCollision->Death();
	}
	CubeMoveDeathCheck(G_TitleCubesCollision);
}

void G_TitleCube::Render(float _Delta)
{

};

void G_TitleCube::BallCheckEvent()
{
	DeathCheck = true;
};


