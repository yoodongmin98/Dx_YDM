#include "PrecompileHeader.h"
#include "BackSqirrelKey.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "SquirrelCloud_Need.h"
#include "SquirrelCloud_Crack.h"
#include "ColManager.h"
#include "Mouse.h"

BackSqirrelKey::BackSqirrelKey()
{
}

BackSqirrelKey::~BackSqirrelKey()
{
}
bool BackKeyLoad = true;
void BackSqirrelKey::Start()
{
	if (true == BackKeyLoad)
	{
		AnimationImageLoad("SquirrelKey");
		BackKeyLoad = false;
	}
	BackSqirrelKeys = AnimationInit(BackSqirrelKeys, "SquirrelKey_Shake1.png", { 217,69 }, { -2,4,0 }, "ShakeKey", "SquirrelKey", 1, 0.1f, false);
	BackSqirrelKeysCollision = CollisionInit(BackSqirrelKeysCollision, { 217,69 }, { 0,0,0 });

}

void BackSqirrelKey::Update(float _DeltaTime)
{
	ManagedCollision(BackSqirrelKeysCollision, 0);
	if (true == ClickCheck(BackSqirrelKeysCollision))
	{
		BackSqirrelKeys->ChangeAnimation("ShakeKey");
		SquirrelCloud_NeedPtr = GetLevel()->CreateActor<SquirrelCloud_Need>();
	}
	CollisionInteractableCheck();
}

void BackSqirrelKey::Render(float _Delta)
{

};


void BackSqirrelKey::CollisionInteractableCheck()
{
	if (BackSqirrelKeysCollision->Collision(ActorTypeEnum::Nut_Close, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		BackSqirrelKeys->ChangeAnimation("ShakeKey");
		GetLevel()->CreateActor<SquirrelCloud_Crack>();
	}
	if (BackSqirrelKeysCollision->Collision(ActorTypeEnum::Nut_Open, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		//¿©±â
		int a = 0;
	}
}