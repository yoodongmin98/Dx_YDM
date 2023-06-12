#include "PrecompileHeader.h"
#include "R_Dos.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
R_Dos* R_Dos::Dos;
R_Dos::R_Dos()
{
	Dos = this;
}

R_Dos::~R_Dos()
{
}

void R_Dos::Start()
{
	float4 Position = { 500,-540,0 };
	R_Doss = Init(R_Doss, "Icon_Shifumi_Voix_Dos.png", { 232,350 }, Position);
	R_DossCollision = CollisionInit(R_DossCollision, { 232,350 }, Position);
}

void R_Dos::Update(float _DeltaTime)
{
	

}

void R_Dos::Render(float _Delta)
{
	
};


//Functional
void R_Dos::Up()
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

void R_Dos::Shake()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	++RotateCount;
	if (RotateCount <= 360)
	{
		R_Doss->GetTransform()->AddLocalRotation({ 0,0,1.0f });
	}
}
