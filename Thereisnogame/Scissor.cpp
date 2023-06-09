#include "PrecompileHeader.h"
#include "Scissor.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"

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

	//¾ê´Â µû·ÎActor·Î¸¸µéÁö °í¹Î.
	//Scissors_Cut = Init(Scissors_Cut, "Scissor_OBJ_Cut.png", { 175,171 }, Position);

	ScissorsCollision = CollisionInit(ScissorsCollision, { 191,173 }, Position);
}

void Scissor::Update(float _DeltaTime)
{
	CatchCheck(Scissors, Scissors_overlap, ScissorsCollision);
}

void Scissor::Render(float _Delta)
{

};
