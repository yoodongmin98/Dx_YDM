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
	GameBall_TitleCubesCollisionU = BallCollisionInit(GameBall_TitleCubesCollisionU, { 27,5 }, Position + float4::Up * 24);
	GameBall_TitleCubesCollisionD = BallCollisionInit(GameBall_TitleCubesCollisionD, { 27,5 }, Position + float4::Down * 24);
	GameBall_TitleCubesCollisionL = BallCollisionInit(GameBall_TitleCubesCollisionL, { 5,39 }, Position + float4::Left * 17);
	GameBall_TitleCubesCollisionR = BallCollisionInit(GameBall_TitleCubesCollisionR, { 5,39 }, Position + float4::Right * 17);
	Sound = Play(Sound, "Chap01CasseBrique01.wav", 0.1f);
	PlaywithinaplayLevel::LM->ChangeBGM("Chap01_MusicA.wav");

}

void GameBall_TitleCube::Update(float _DeltaTime)
{
	SoundAndText(_DeltaTime);
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
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
		Rigids->ChangeYDir();
	}
	if (GetTransform()->GetLocalPosition().x < -940 + 22
		|| GetTransform()->GetLocalPosition().x > 352 - 22)
	{
		InterBool = false;
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
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
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
		if (GetTransform()->GetLocalPosition().x < RQXpos - 20
			&& GetTransform()->GetLocalPosition().x > RQXpos - 40)
		{
			InterBool = false;
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->AddForce(float4::Left * 15000); 
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x < RQXpos - 40)
		{
			InterBool = false;
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->AddForce(float4::Left * 15000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x > RQXpos + 20
			&& GetTransform()->GetLocalPosition().x < RQXpos + 40)
		{
			InterBool = false;
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->AddForce(float4::Right * 15000);
			_Rigids->ChangeYDir();
		}
		else if (GetTransform()->GetLocalPosition().x > RQXpos + 40)
		{
			InterBool = false;
			_Rigids->AddForce(float4::Down * 10000);
			_Rigids->AddForce(float4::Right * 15000);
			_Rigids->ChangeYDir();
		}
		else
		{
			InterBool = false;
			_Rigids->AddForce(float4::Down * 15000);
			_Rigids->ChangeYDir();
		}
	}
	else if ((GameBall_TitleCubesCollisionL->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		InterBool = false;
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
		_Rigids->AddForce(float4::Down * 10000);
		_Rigids->AddForce(float4::Left * 25000);
		_Rigids->ChangeXDir();
	}
	else if ((GameBall_TitleCubesCollisionR->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		InterBool = false;
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
		_Rigids->AddForce(float4::Down * 10000);
		_Rigids->AddForce(float4::Right * 25000);
		_Rigids->ChangeXDir();
	}
}

void GameBall_TitleCube::CubeCrashCheck(G_RigidBody* _Rigids)
{
	if ((GameBall_TitleCubesCollisionD->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D))
		|| (GameBall_TitleCubesCollisionU->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		InterBool = false;
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
		_Rigids->ChangeYDir();
	}
	else if((GameBall_TitleCubesCollisionL->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D))
		|| (GameBall_TitleCubesCollisionR->Collision(ActorTypeEnum::Block, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		InterBool = false;
		Sound = Play(Sound, "BallBounce.wav", 0.1f);
		_Rigids->ChangeXDir();
	}
}

void GameBall_TitleCube::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	Font = NFontCreate(Font, "내 제목!", GetTransform(), 1.0f);
	if (SoundTime > 2.0f)
	{
		static bool Play24 = true;
		if (true == Play24)
		{
			LevelStateManager::MG->SetplaqueNarateTrue();
			Sound = Play(Sound, "Chap01CasseBrique02.wav", 0.1f);
			Play24 = false;
		}
		Font2 = NFontCreate(Font2, "그만해요! 다 망가뜨리잖아요!", GetTransform(), 2.5f);
	}

	if (SoundTime > 5.0f)
	{
		static bool Play25 = true;
		if (true == Play25)
		{
			Sound = Play(Sound, "Chap01CasseBrique03.wav", 0.1f);
			Play25 = false;
		}
		Font3 = NFontCreate(Font3, "저 글자 다 붙이는 데 기계 시간으로 얼마나 걸리는지 알기나 해요?", GetTransform(), 4.5f);
	}

	if (SoundTime > 11.0f)
	{
		static bool Play25 = true;
		if (true == Play25)
		{
			Sound = Play(Sound, "ChainUp.wav", 0.1f);
			Sound = Play(Sound, "Chap01CasseBrique04.wav", 0.1f);
			Play25 = false;
		}
		Font4 = NFontCreate(Font4, "이거 다 다시 붙여야 하잖아요!", GetTransform(), 3.5f);
	}

	if (SoundTime > 16.0f)
	{
		static bool Play26 = true;
		if (true == Play26)
		{
			Sound = Play(Sound, "Chap01CasseBrique04b.wav", 0.1f);
			Play26 = false;
		}
		Font5 = NFontCreate(Font5, "아 사슬이 막혔네...", GetTransform(), 3.0f);
	}

	if (SoundTime > 20.0f)
	{
		static bool Play27 = true;
		if (true == Play27)
		{
			Sound = Play(Sound, "Chap01CasseBrique05.wav", 0.1f);
			Play27 = false;
		}
		Font6 = NFontCreate(Font6, "해 보쇼. 맘대로 말이에요. 내가 졌네요.", GetTransform(), 3.0f);
	}

	if (SoundTime > 25.0f)
	{
		static bool Play28 = true;
		if (true == Play28)
		{
			Sound = Play(Sound, "Chap01CasseBrique06.wav", 0.1f);
			Play28 = false;
		}
		Font7 = NFontCreate(Font7, "오호. 멋지네요... 벽돌 깨기라.", GetTransform(), 3.5f);
	}

	if (SoundTime > 29.0f)
	{
		static bool Play29 = true;
		if (true == Play29)
		{
			Sound = Play(Sound, "Chap01CasseBrique07.wav", 0.1f);
			Play29 = false;
		}
		Font8 = NFontCreate(Font8, "GOTY 감이네.", GetTransform(), 2.0f);
	}
}