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

	GameEngineInput::CreateKey("Left", 'A');
	GameEngineInput::CreateKey("Up", 'W');
	GameEngineInput::CreateKey("Down", 'S');
	GameEngineInput::CreateKey("Right", 'D');
}

void Ball_TitleCube::Update(float _DeltaTime)
{
	G_RigidBody* Rigids = GetRigidBody();
	if (GameEngineInput::IsPress("Down"))
	{
		Rigids->AddForce(float4{0.0f,-200.0f});
	}
	if (GameEngineInput::IsPress("Up"))
	{
		Rigids->AddForce(float4{ 0.0f,200.0f });
	}
	if (GameEngineInput::IsPress("Right"))
	{
		Rigids->AddForce(float4{ 200.0f,0.0f });
	}
	if (GameEngineInput::IsPress("Left"))
	{
		Rigids->AddForce(float4{ -200.0f,0.0f });
	}
	Rigids->RigidBodyUpdate();
	//if (true == LevelStateManager::MG->GetIsBoardDown()
	//	&& true == UpdateBool)
	//{
	//	UpdateBool = false;
	//	GetTransform()->SetLocalRotation({ 0,0,-30 });
	//	GetTransform()->AddLocalPosition({ -30,-20,0 });
	//	Ball_TitleCubesCollision->On();
	//}
}

void Ball_TitleCube::Render(float _Delta)
{

};

void Ball_TitleCube::StartRigidBody()
{

}
