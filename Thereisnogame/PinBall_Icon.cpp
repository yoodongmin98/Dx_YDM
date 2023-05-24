#include "PrecompileHeader.h"
#include "PinBall_Icon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"

PinBall_Icon::PinBall_Icon()
{
}

PinBall_Icon::~PinBall_Icon()
{
}

void PinBall_Icon::Start()
{
	PinBall_Icons = Init(PinBall_Icons, "Pinball.png", { 75,75 }, {-330,20,0});
	PinBall_IconsCollision = CollisionInit(PinBall_IconsCollision, { 75,75 }, { -330,20,0 });
}

void PinBall_Icon::Update(float _DeltaTime)
{
	ManagedCollision(PinBall_IconsCollision, 1);
	if (true == ClickCheck(PinBall_IconsCollision))
	{
		//얘는 나중에하기 rigidbody어떻게 쓰는지 알때까지
		int a = 0;
	}
}

void PinBall_Icon::Render(float _Delta)
{

};
