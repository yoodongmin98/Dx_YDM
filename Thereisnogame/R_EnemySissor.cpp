#include "PrecompileHeader.h"
#include "R_EnemySissor.h"
#include <math.h>
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

#include <GameEngineBase/GameEngineTime.h>


//Actor
#include "LevelStateManager.h"
#include "Scissor.h"
#include "Mouse.h"

R_EnemySissor::R_EnemySissor()
{
}

R_EnemySissor::~R_EnemySissor()
{
}

void R_EnemySissor::Start()
{
	float4 Position = { 500,-540,0 };
	R_EnemySissorsNone = Init(R_EnemySissorsNone, "Icon_Shifumi_Voix_FaceEmpty.png", { 245,362 }, Position);
	R_EnemySissors = Init(R_EnemySissors, "Icon_Shifumi_Voix_Scissor.png", { 232,350 }, Position);
	R_EnemySissorsCollision = CollisionInit(R_EnemySissorsCollision, { 232,350 }, Position);
	Off();
}

void R_EnemySissor::Update(float _DeltaTime)
{
	if (true == ClickCheck(R_EnemySissorsCollision))
	{
		R_EnemySissorsNone->On();
		R_EnemySissors->Off();
		ScissorPtr=GetLevel()->CreateActor<Scissor>();
		if (true == ScissorPtr.get()->IsDeath())
		{
			R_EnemySissorsNone->Off();
			R_EnemySissors->On();
		}
	}
	
}

void R_EnemySissor::Render(float _Delta)
{

};

//Functional
void R_EnemySissor::Up()
{
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,1,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 280.0f)
	{
		float4 Tests = GetTransform()->GetLocalPosition();
		GetTransform()->SetLocalPosition(GetTransform()->GetLocalPosition());
		IsPos = true;
	}
}
