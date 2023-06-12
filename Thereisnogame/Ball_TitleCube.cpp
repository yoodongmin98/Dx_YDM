#include "PrecompileHeader.h"
#include "Ball_TitleCube.h"
#include "G_RigidBody.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "GameBall_TitleCube.h"
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
	ProgressCheck();
}

void Ball_TitleCube::Render(float _Delta)
{

};

void Ball_TitleCube::ProgressCheck()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (true==LevelStateManager::MG->GetIsCreateRaquette()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		Ball_TitleCubesCollision->On();
	}
	if (true == ClickCheck(Ball_TitleCubesCollision)&& 5>BallClickCount)
	{
		++BallClickCount;
		GetTransform()->AddLocalPosition({ 0,-5*Times,0 });
		if (BallClickCount > 4)
		{
			GetLevel()->CreateActor<GameBall_TitleCube>();
			Death();
		}
	}
}


