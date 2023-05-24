#include "PrecompileHeader.h"
#include "SquirrelKeySmall.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Mouse.h"

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
}

void SquirrelKeySmall::Update(float _DeltaTime)
{
	Fall(SquirrelKeySmalls, SquirrelKeySmall_overlap, SquirrelKeySmallCollision, 39.5f, _DeltaTime);
	CatchCheck(SquirrelKeySmalls, SquirrelKeySmall_overlap, SquirrelKeySmallCollision);
	if (SquirrelKeySmallCollision->Collision(ActorTypeEnum::LockFolder, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		MsgAssert("엔딩까지 도달했습니다 일단 멈추십쇼");
		Death();
	}
}

void SquirrelKeySmall::Render(float _Delta)
{

};


