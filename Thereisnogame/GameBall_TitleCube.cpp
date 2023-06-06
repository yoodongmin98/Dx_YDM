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

GameBall_TitleCube::GameBall_TitleCube()
{
}

GameBall_TitleCube::~GameBall_TitleCube()
{
}

void GameBall_TitleCube::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	GameBall_TitleCubes = Init(GameBall_TitleCubes, "TitleCube_Ball.png", { 44,58 }, Position);
	GameBall_TitleCubesCollisionU = CollisionInit(GameBall_TitleCubesCollisionU, { 42,5 }, Position + float4::Up * 28);
	GameBall_TitleCubesCollisionD = CollisionInit(GameBall_TitleCubesCollisionD, { 42,5 }, Position + float4::Down * 28);
	GameBall_TitleCubesCollisionL = CollisionInit(GameBall_TitleCubesCollisionL, { 5,56 }, Position + float4::Left * 22);
	GameBall_TitleCubesCollisionR = CollisionInit(GameBall_TitleCubesCollisionR, { 5,56 }, Position + float4::Right * 22);
}

void GameBall_TitleCube::Update(float _DeltaTime)
{
	StartRigidBody();
}

void GameBall_TitleCube::Render(float _Delta)
{

};

void GameBall_TitleCube::StartRigidBody()
{
	G_RigidBody* Rigids = GetRigidBody();
	Rigids->AddForce(float4::Down * 500);
	if (GetTransform()->GetLocalPosition().y <= -280 +29
		|| GetTransform()->GetLocalPosition().y >= 460)
	{
		Rigids->ChangeYDir();
	}
	if (GetTransform()->GetLocalPosition().x < -940 + 22
		|| GetTransform()->GetLocalPosition().x > 352 - 22)
	{
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
			&& GetTransform()->GetLocalPosition().x < RQXpos - 40)
		{
			_Rigids->AddForce(float4::Left * 15000); 
			_Rigids->AddForce(float4::Down * 1000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos - 40)
		{
			_Rigids->AddForce(float4::Left * 25000);
			_Rigids->AddForce(float4::Down * 1000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos + 20
			&& GetTransform()->GetLocalPosition().x < RQXpos + 40)
		{
			_Rigids->AddForce(float4::Right * 15000);
			_Rigids->AddForce(float4::Down * 1000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x > RQXpos + 40)
		{
			_Rigids->AddForce(float4::Right * 25000);
			_Rigids->AddForce(float4::Down * 1000);
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
		_Rigids->AddForce(float4::Down * 1500);
		_Rigids->AddForce(float4::Left * 25000);
		_Rigids->ChangeXDir();
	}
	else if ((GameBall_TitleCubesCollisionR->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->AddForce(float4::Down * 1500);
		_Rigids->AddForce(float4::Right * 25000);
		_Rigids->ChangeXDir();
	}
}

void GameBall_TitleCube::CubeCrashCheck(G_RigidBody* _Rigids)
{
	/*float Times = GameEngineTime::GlobalTime.GetDeltaTime();
	float NextXPos = GetTransform()->GetLocalPosition().x * Times;*/
	if ((GameBall_TitleCubesCollisionD->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D))
		|| (GameBall_TitleCubesCollisionU->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->AddForce(float4::Up * 1500);
		_Rigids->ChangeYDir();
	}
	else if((GameBall_TitleCubesCollisionL->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D))
		|| (GameBall_TitleCubesCollisionR->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		_Rigids->ChangeXDir();
	}
}