#include "PrecompileHeader.h"
#include "R_EnemyRock.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_EnemyRock::R_EnemyRock()
{
}

R_EnemyRock::~R_EnemyRock()
{
}

void R_EnemyRock::Start()
{
	float4 Position = { 500,-540,0 };
	R_EnemyRocks = Init(R_EnemyRocks, "Icon_Shifumi_Voix_Rock.png", { 232,350 }, Position);
	R_EnemyRocksCollision = CollisionInit(R_EnemyRocksCollision, { 232,350 }, Position);
	Off();
}

void R_EnemyRock::Update(float _DeltaTime)
{

}

void R_EnemyRock::Render(float _Delta)
{

};

void R_EnemyRock::Up()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 280.0f)
	{
		float4 Tests = GetTransform()->GetLocalPosition();
		GetTransform()->SetLocalPosition(GetTransform()->GetLocalPosition());
		IsPos = true;
	}
}

