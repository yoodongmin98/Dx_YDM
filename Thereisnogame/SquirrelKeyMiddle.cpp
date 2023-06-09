#include "PrecompileHeader.h"
#include "SquirrelKeyMiddle.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Mouse.h"
#include "SquirrelKeySmall.h"
SquirrelKeyMiddle::SquirrelKeyMiddle()
{
}

SquirrelKeyMiddle::~SquirrelKeyMiddle()
{
}

void SquirrelKeyMiddle::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	SquirrelKeyMiddles = Init(SquirrelKeyMiddles, "SquirrelKey_KeySemiSmall.png", { 106,118 }, Position);
	SquirrelKeyMiddle_overlap = Init(SquirrelKeyMiddle_overlap, "SquirrelKey_KeySemiSmall_Overlap.png", { 137, 149 }, { Position.x - 3,Position.y + 3 });

	SquirrelKeyMiddleCollision = CollisionInit(SquirrelKeyMiddleCollision, { 106,118 }, Position);
}

void SquirrelKeyMiddle::Update(float _DeltaTime)
{
	Fall(SquirrelKeyMiddles, SquirrelKeyMiddle_overlap, SquirrelKeyMiddleCollision, 59.0f, _DeltaTime);
	CatchCheck(SquirrelKeyMiddles, SquirrelKeyMiddle_overlap, SquirrelKeyMiddleCollision);
	if (GetLiveTime() > 1.0f) //생성되자마자 사라지는걸 방지
	{
		CollisionInteractableCheck();
	}
}

void SquirrelKeyMiddle::Render(float _Delta)
{

};
bool KeySmall = false;
void SquirrelKeyMiddle::CollisionInteractableCheck()
{
	if (SquirrelKeyMiddleCollision->Collision(ActorTypeEnum::ZipWip, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		if (false == KeySmall)
		{
			GetLevel()->CreateActor<SquirrelKeySmall>();
			KeySmall = true;
			Death();
		}
	}
}
