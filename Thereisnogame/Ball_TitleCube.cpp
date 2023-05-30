#include "PrecompileHeader.h"
#include "Ball_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

Ball_TitleCube::Ball_TitleCube()
{
}

Ball_TitleCube::~Ball_TitleCube()
{
}

void Ball_TitleCube::Start()
{
	Ball_TitleCubes = Init(Ball_TitleCubes, "TitleCube_Ball.png", { 44,58 }, { 300,-30,0 });
	Ball_TitleCubesCollision = CollisionInit(Ball_TitleCubesCollision, { 44,58 }, { 300,-30,0 });
	Ball_TitleCubesCollision->Off();
}

void Ball_TitleCube::Update(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetIsBoardDown()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		Ball_TitleCubes->GetTransform()->SetLocalRotation({ 0,0,-30 });
		Ball_TitleCubesCollision->On();
	}
}

void Ball_TitleCube::Render(float _Delta)
{

};


