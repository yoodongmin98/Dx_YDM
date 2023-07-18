#include "PrecompileHeader.h"
#include "SquirrelKeySmall.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Mouse.h"
#include "FadeEffect.h"

SquirrelKeySmall::SquirrelKeySmall()
{
}

SquirrelKeySmall::~SquirrelKeySmall()
{
}

void SquirrelKeySmall::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	SquirrelKeySmalls = Init(SquirrelKeySmalls, "SquirrelKey_KeySmall.png", { 70,79 }, Position);
	SquirrelKeySmall_overlap = Init(SquirrelKeySmall_overlap, "SquirrelKey_KeySmall_Overlap.png", { 101,110 }, { Position.x - 3,Position.y + 3 });

	SquirrelKeySmallCollision = CollisionInit(SquirrelKeySmallCollision, { 106,118 }, Position);

	FEffect = GetLevel()->GetLastTarget()->CreateEffect<FadeEffect>();
}


void SquirrelKeySmall::Update(float _DeltaTime)
{
	Fall(SquirrelKeySmalls, SquirrelKeySmall_overlap, SquirrelKeySmallCollision, 39.5f, _DeltaTime);
	CatchCheck(SquirrelKeySmalls, SquirrelKeySmall_overlap, SquirrelKeySmallCollision);

	if (SquirrelKeySmallCollision->Collision(ActorTypeEnum::LockFolder, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		LevelChangeBool = false;
		FEffect->FadeIn();
		SquirrelKeySmalls->Death();
		SquirrelKeySmall_overlap->Death();
		SquirrelKeySmallCollision->Death();
	}
	if (false == LevelChangeBool)
	{
		LevelChangeTime += _DeltaTime;
		if (LevelChangeTime > 3.0f)
		{
			GameEngineCore::ChangeLevel("EndingLevel");
		}
	}
}

void SquirrelKeySmall::Render(float _Delta)
{

};


