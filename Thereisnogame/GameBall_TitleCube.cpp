#include "PrecompileHeader.h"
#include "GameBall_TitleCube.h"
#include "G_RigidBody.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
#include <GameEngineBase/GameEngineTime.h>
//Core
#include <GameEnginePlatform/GameEngineInput.h>

//Actor
#include "LevelStateManager.h"
#include "Raquette_TitleCube.h"
#include "Mouse.h"
#include "Play within a play Level.h"

GameBall_TitleCube::GameBall_TitleCube()
{
}

GameBall_TitleCube::~GameBall_TitleCube()
{
}

void GameBall_TitleCube::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	GameBall_TitleCubes = Init(GameBall_TitleCubes, "TitleCube_Ball_Rebond.png", { 33,45 }, Position);
	GameBall_TitleCubesCollisionU = BallCollisionInit(GameBall_TitleCubesCollisionU, { 29,5 }, Position + float4::Up * 21);
	GameBall_TitleCubesCollisionD = BallCollisionInit(GameBall_TitleCubesCollisionD, { 29,5 }, Position + float4::Down * 21);
	GameBall_TitleCubesCollisionL = BallCollisionInit(GameBall_TitleCubesCollisionL, { 5,41 }, Position + float4::Left * 14);
	GameBall_TitleCubesCollisionR = BallCollisionInit(GameBall_TitleCubesCollisionR, { 5,41 }, Position + float4::Right * 14);
}

void GameBall_TitleCube::Update(float _DeltaTime)
{
	InterBoolTime += _DeltaTime;
	if (InterBoolTime > 0.1f)
	{
		InterBoolTime = 0.0f;
		InterBool = true;
	}
	StartRigidBody();

	if (Chap1LevelState::ClearBoard == PlaywithinaplayLevel::LM->GetLevelState())
	{
		Death();
	}
}

void GameBall_TitleCube::Render(float _Delta)
{

};

void GameBall_TitleCube::StartRigidBody()
{
	G_RigidBody* Rigids = GetRigidBody();
	Rigids->AddForce(float4::Down * 500);
	if (GetTransform()->GetLocalPosition().y < -280 +29
		|| GetTransform()->GetLocalPosition().y > 460)
	{
		InterBool = false;
		Rigids->ChangeYDir();
	}
	if (GetTransform()->GetLocalPosition().x < -940 + 22
		|| GetTransform()->GetLocalPosition().x > 352 - 22)
	{
		InterBool = false;
		Rigids->ChangeXDir();
	}
	CollisionInterCheck(Rigids);
	CubeCrashCheck(Rigids);
	Rigids->RigidBodyUpdate();
}

void GameBall_TitleCube::CollisionInterCheck(G_RigidBody* _Rigids)
{
	float RQXpos=Raquette_TitleCube::RQ->GetCollisionPos();
	if ((GameBall_TitleCubesCollisionD->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		if (GetTransform()->GetLocalPosition().x < RQXpos - 20
			&& GetTransform()->GetLocalPosition().x > RQXpos - 40)
		{
			_Rigids->AddForce(float4::Left * 15000); 
			_Rigids->AddForce(float4::Down * 1000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos - 40)
		{
			_Rigids->AddForce(float4::Left * 25000);
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x > RQXpos + 20
			&& GetTransform()->GetLocalPosition().x < RQXpos + 40)
		{
			_Rigids->AddForce(float4::Right * 15000);
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x > RQXpos + 40)
		{
			_Rigids->AddForce(float4::Right * 25000);
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->ChangeYDir();
		}
		else
		{
			_Rigids->AddForce(float4::Down * 1000);
			_Rigids->ChangeYDir();
		}
	}
	else if ((GameBall_TitleCubesCollisionL->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->AddForce(float4::Down * 15000);
		_Rigids->AddForce(float4::Left * 25000);
		_Rigids->ChangeXDir();
	}
	else if ((GameBall_TitleCubesCollisionR->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->AddForce(float4::Down * 15000);
		_Rigids->AddForce(float4::Right * 25000);
		_Rigids->ChangeXDir();
	}
}

void GameBall_TitleCube::CubeCrashCheck(G_RigidBody* _Rigids)
{
	if ((GameBall_TitleCubesCollisionD->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D))
		|| (GameBall_TitleCubesCollisionU->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->ChangeYDir();
	}
	else if((GameBall_TitleCubesCollisionL->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D))
		|| (GameBall_TitleCubesCollisionR->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->ChangeXDir();
	}
}