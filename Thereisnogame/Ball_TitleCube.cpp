#include "PrecompileHeader.h"
#include "Ball_TitleCube.h"
#include "G_RigidBody.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEnginePlatform/GameEngineInput.h>

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

	ImageHalfScaleX = Ball_TitleCubes->GetTransform()->GetLocalScale().half().x;
	ImageHalfScaleY = Ball_TitleCubes->GetTransform()->GetLocalScale().half().y;
	if (false == GameEngineInput::IsKey("BallLeft"))
	{
		GameEngineInput::CreateKey("BallLeft", 'A');
		GameEngineInput::CreateKey("BallRight", 'D');
	}
}

void Ball_TitleCube::Update(float _DeltaTime)
{
	if (true == StartBallGame)
	{
		StartRigidBody();
	}
	ProgressCheck();
}

void Ball_TitleCube::Render(float _Delta)
{

};

void Ball_TitleCube::StartRigidBody()
{
	G_RigidBody* Rigids = GetRigidBody();
	Rigids->AddForce(float4::Down * 400);
	if (GetTransform()->GetLocalPosition().y <= -280 - ImageHalfScaleY)
	{
		Rigids->ChangeYDir();
	}
	if (GetTransform()->GetLocalPosition().x < -940 + ImageHalfScaleX
		|| GetTransform()->GetLocalPosition().x > 352 - ImageHalfScaleX)
	{
		Rigids->ChangeXDir();
	}
	CollisionInterCheck(Rigids);
	Rigids->RigidBodyUpdate();
}

void Ball_TitleCube::ProgressCheck()
{
	if (true == LevelStateManager::MG->GetIsBoardDown()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		Ball_TitleCubesCollision->On();
	}
	if (true == ClickCheck(Ball_TitleCubesCollision)&&false== StartBallGame&& 5>BallClickCount)
	{
		++BallClickCount;
		GetTransform()->AddLocalPosition({ 0,-5,0 });
		if (BallClickCount > 4)
		{
			StartBallGame = true;
		}
	}
}

void Ball_TitleCube::CollisionInterCheck(G_RigidBody* _Rigids)
{
	if (Ball_TitleCubesCollision->Collision(ActorTypeEnum::Excla,ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		_Rigids->AddForce(float4::Down * 400); //힘을 주고나서,
		_Rigids->ChangeYDir(); //방향을 바꾼다.
	}
}
