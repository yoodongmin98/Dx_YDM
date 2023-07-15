#include "PrecompileHeader.h"
#include "Excla_TitleCube.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Raquette_TitleCube.h"

Excla_TitleCube::Excla_TitleCube()
{
}

Excla_TitleCube::~Excla_TitleCube()
{
}

void Excla_TitleCube::Start()
{
	Excla_TitleCubes = Init(Excla_TitleCubes, "TitleCube_Excla.png", { 45,109 }, { 300,40,0 });
	Excla_TitleCubesCollision = CollisionInit(Excla_TitleCubesCollision, { 45,109 }, { 300,40,0 });
	Excla_TitleCubesCollision->Off();
}

void Excla_TitleCube::Update(float _DeltaTime)
{
	ProgressCheck();
}

void Excla_TitleCube::Render(float _Delta)
{

};

void Excla_TitleCube::ProgressCheck()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (true == LevelStateManager::MG->GetIsBoardDown()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		Excla_TitleCubesCollision->On();
	}

	if (true == ClickCheck(Excla_TitleCubesCollision))
	{
		Sound = Play(Sound, "ExclaClick.wav", 0.1f);
		GetTransform()->AddLocalPosition({ 0,-5*Times,0 });
		++ExclaClickCount;
		if (ExclaClickCount > 4)
		{
			Excla_TitleCubesCollision->Death();
			FallAndDeathCheck = true;
		}
	}

	if (true == FallAndDeathCheck)
	{
		GetTransform()->AddLocalPosition({ 0,-5*Times,0 });
		if (GetTransform()->GetLocalPosition().y < -360 + 55)
		{
			GetLevel()->CreateActor<Raquette_TitleCube>();
			Death();
		}
	}
}


