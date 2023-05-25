#include "PrecompileHeader.h"
#include "SkiteCallingMissed.h"




//PlatForm
//Core


//Actor
#include "LevelStateManager.h"
SkiteCallingMissed::SkiteCallingMissed()
{
}

SkiteCallingMissed::~SkiteCallingMissed()
{
}

void SkiteCallingMissed::Start()
{
	SkiteCallingMisseds=Init(SkiteCallingMisseds, "SkiteCalling02.png", { 96,96 }, { 55,-110,0 });
	SkiteCallingMissedsCollision = CollisionInit(SkiteCallingMissedsCollision, { 64,64 }, { 55,-110,0 });
}

void SkiteCallingMissed::Update(float _DeltaTime)
{
	if (true == ClickCheck(SkiteCallingMissedsCollision))
	{
		SkiteCallingMissedsCollision->Death();
		SkiteCallingMisseds->GetTransform()->AddLocalRotation({ 0,0,-45.0f });
		FallStart = true;
	}
	FallandDeathCheck();
}

void SkiteCallingMissed::Render(float _Delta)
{

};

void SkiteCallingMissed::FallandDeathCheck()
{
	if (true == FallStart)
	{
		SkiteCallingMisseds->GetTransform()->AddLocalPosition({ 0,-5,0 });
	}
	if (SkiteCallingMisseds->GetTransform()->GetLocalPosition().y < -500.0f
		|| 1 != LevelStateManager::MG->GetCollisionValue())
	{
		Death();
	}
}