#include "PrecompileHeader.h"
#include "Scissor_Fall.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"

ScissorDeath::ScissorDeath()
{
}

ScissorDeath::~ScissorDeath()
{
}

void ScissorDeath::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	ScissorDeaths = Init(ScissorDeaths, "Scissor_OBJ_Cut.png", { 175,171 }, Position);
	Sound = Play(Sound, "CordeCut.wav", 0.1f);
}

void ScissorDeath::Update(float _DeltaTime)
{
	ScissorDeaths->GetTransform()->AddLocalPosition({ 0,-1500 * _DeltaTime ,0 });
	if (ScissorDeaths->GetTransform()->GetLocalPosition().y < -1000)
	{
		Death();
	}
}

void ScissorDeath::Render(float _Delta)
{

};
