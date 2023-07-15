#include "PrecompileHeader.h"
#include "R_Dos.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"

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
	static bool Play54 = true;
	if (true == Play54)
	{
		Sound = Play(Sound, "CardDrop.wav", 0.1f);
		Play54 = false;
	}
	if (false == IsPos)
	{
		GetTransform()->AddLocalPosition({ 0,2*Times,0 });
	}
	if (GetTransform()->GetLocalPosition().y >= 280.0f)
	{
		GetTransform()->SetLocalPosition(GetTransform()->GetLocalPosition());
		IsPos = true;
	}
}

void R_Dos::Shake()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 360;
	
	R_Doss->GetTransform()->AddLocalRotation({ 0,0,1.0f * Times });
}
