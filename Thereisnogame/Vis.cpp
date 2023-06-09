#include "PrecompileHeader.h"
#include "Vis.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
Vis::Vis()
{
}

Vis::~Vis()
{
}

void Vis::Start()
{
	Viss = Init(Viss, "Vis.png", { 31,31 }, float4::Zero);
	VissCollision = CollisionInit(VissCollision, { 31,31 }, float4::Zero);
	VissCollision->Off();
}

void Vis::Update(float _DeltaTime)
{
	if (true == SettingBools && float4::Zero != Position)
	{
		Viss->GetTransform()->SetLocalPosition(Position);
		VissCollision->GetTransform()->SetLocalPosition(Position);
		Viss->GetTransform()->SetLocalRotation(RotateValue);
		SettingBools = false;
	}
}

void Vis::Render(float _Delta)
{

};
