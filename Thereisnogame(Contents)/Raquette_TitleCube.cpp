#include "PrecompileHeader.h"
#include "Raquette_TitleCube.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"
#include "Mouse.h"
#include "Play within a play Level.h"

Raquette_TitleCube* Raquette_TitleCube::RQ;
Raquette_TitleCube::Raquette_TitleCube()
{
	RQ = this;
	LevelStateManager::MG->SetIsCreateRaquetteTrue();
}

Raquette_TitleCube::~Raquette_TitleCube()
{
}

void Raquette_TitleCube::Start()
{
	Raquette_TitleCubes = Init(Raquette_TitleCubes, "Raquette.png", { 151,74 }, { 300,-330,0 });

	Raquette_TitleCubesCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Excla);
	Raquette_TitleCubesCollision->GetTransform()->SetLocalScale({ 151,74 });
	Raquette_TitleCubesCollision->GetTransform()->SetLocalPosition({ 300,-330,0 });
}

void Raquette_TitleCube::Update(float _DeltaTime)
{
	CatchMoveCheck();
	if (Chap1LevelState::ClearBoard == PlaywithinaplayLevel::LM->GetLevelState())
	{
		Death();
	}
}

void Raquette_TitleCube::Render(float _Delta)
{

};

void Raquette_TitleCube::CatchMoveCheck()
{
	if (Raquette_TitleCubesCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		float4 MousePos = Mouse::MainMouse->GetMousePos();
		if (false == Mouse::MainMouse->IsInteractable())
		{
			Raquette_TitleCubes->GetTransform()->SetLocalPosition({ MousePos.x,Raquette_TitleCubes->GetTransform()->GetLocalPosition().y });
			Raquette_TitleCubesCollision->GetTransform()->SetLocalPosition({ MousePos.x,Raquette_TitleCubesCollision->GetTransform()->GetLocalPosition().y });
		}
	}
}

