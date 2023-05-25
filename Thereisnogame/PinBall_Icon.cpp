#include "PrecompileHeader.h"
#include "PinBall_Icon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "Cup.h"

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
		LevelStateManager::MG->PlusCollisionValue();
		//얘는 나중에하기 rigidbody어떻게 쓰는지 알때까지
		//임시
		if (false == LevelStateManager::MG->GetIsGetTheCup())
		{
			CupPtr = GetLevel()->CreateActor<Cup>();
		}
	}
}

void PinBall_Icon::Render(float _Delta)
{

};
