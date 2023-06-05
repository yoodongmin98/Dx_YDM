#include "PrecompileHeader.h"
#include "GameBall_TitleCube.h"
#include "G_RigidBody.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
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
	GameBall_TitleCubesCollision = CollisionInit(GameBall_TitleCubesCollision, { 44,58 }, Position);
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
	Rigids->AddForce(float4::Down * 400);
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
	Rigids->RigidBodyUpdate();
}

void GameBall_TitleCube::CollisionInterCheck(G_RigidBody* _Rigids)
{
	float RQXpos=Raquette_TitleCube::RQ->GetCollisionPos();
	if ((GameBall_TitleCubesCollision->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		if (GetTransform()->GetLocalPosition().x < RQXpos - 20
			&& GetTransform()->GetLocalPosition().x < RQXpos - 40)
		{
			_Rigids->AddForce(float4::Left * 15000); 
			_Rigids->AddForce(float4::Down * 500);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos - 40)
		{
			_Rigids->AddForce(float4::Left * 25000);
			_Rigids->AddForce(float4::Down * 600);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos + 20
			&& GetTransform()->GetLocalPosition().x < RQXpos + 40)
		{
			_Rigids->AddForce(float4::Right * 15000);
			_Rigids->AddForce(float4::Down * 500);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos + 40)
		{
			_Rigids->AddForce(float4::Right * 25000);
			_Rigids->AddForce(float4::Down * 600);
			_Rigids->ChangeYDir();
		}
		else
		{
			_Rigids->AddForce(float4::Down * 500);
			_Rigids->ChangeYDir();
		}
	}
}
