#include "PrecompileHeader.h"
#include "Scissor.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"

Scissor::Scissor()
{
}

Scissor::~Scissor()
{
}

void Scissor::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	Scissors = Init(Scissors, "Scissor_OBJ_Default.png", { 191,173 }, Position);
	Scissors_overlap = Init(Scissors_overlap, "Scissor_OBJ_Default_Overlap.png", { 210,192 }, { Position.x - 3,Position.y + 3 });

	ScissorsCollision = CollisionInit(ScissorsCollision, { 191,173 }, Position);

	Sound = Play(Sound, "CardDrop.wav", 0.1f);
}

void Scissor::Update(float _DeltaTime)
{
	if (true == Mouse::MainMouse->IsInteractable())
	{
		LevelStateManager::MG->SetIsPickScissorFalse();
		Death();
	}
	CatchCheck(Scissors, Scissors_overlap, ScissorsCollision);
}

void Scissor::Render(float _Delta)
{

};
