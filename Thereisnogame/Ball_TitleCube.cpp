#include "PrecompileHeader.h"
#include "Ball_TitleCube.h"
#include "G_RigidBody.h"
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

	/*GameEngineInput::CreateKey("Left", 'A');
	GameEngineInput::CreateKey("Up", 'W');
	GameEngineInput::CreateKey("Down", 'S');
	GameEngineInput::CreateKey("Right", 'D');*/
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
	//Test Key
	/*if (GameEngineInput::IsPress("Left"))
	{
		Rigids->AddForce(float4::Left * 300);
	}
	if (GameEngineInput::IsPress("Right"))
	{
		Rigids->AddForce(float4::Right * 200);
	}*/
	Rigids->AddForce(float4::Down * 400);
	if (GetTransform()->GetLocalPosition().y <= -100 - ImageHalfScaleY)
	{
		Rigids->ChangeYDir();
	}
	if (GetTransform()->GetLocalPosition().x < -940 + ImageHalfScaleX
		|| GetTransform()->GetLocalPosition().x > 352 - ImageHalfScaleX)
	{
		Rigids->ChangeXDir();
	}
	Rigids->RigidBodyUpdate();
}

void Ball_TitleCube::ProgressCheck()
{
	if (true == LevelStateManager::MG->GetIsBoardDown()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		GetTransform()->SetLocalRotation({ 0,0,-30 });
		GetTransform()->AddLocalPosition({ 60,140,0 });
		Ball_TitleCubesCollision->On();
	}
	if (true == ClickCheck(Ball_TitleCubesCollision)&&false== StartBallGame)
	{
		++BallClickCount;
		GetTransform()->AddLocalPosition({ 0,-5,0 });
		if (BallClickCount > 4)
		{
			StartBallGame = true;
		}
	}
}
