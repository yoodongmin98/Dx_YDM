#include "PrecompileHeader.h"
#include "BackSqirrelKey.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "SquirrelCloud_Need.h"
#include "SquirrelCloud_Crack.h"
#include "LevelStateManager.h"
#include "Mouse.h"
#include "SquirrelKey.h"

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
		AnimationImageLoad("SquirrelKeyAnimation");
		BackKeyLoad = false;
	}

	BackSqirrelKeys = AnimationInit(BackSqirrelKeys, "SquirrelKey_Shake1.png", { 217,69 }, { -2,4,0 }, "ShakeKey", "SquirrelKey", 1, 0.1f, false);
	BackSqirrelKeys->CreateAnimation({ "FallingKey", "SquirrelKeyAnimation", 0,20,0.05f, false });
	BackSqirrelKeysCollision = CollisionInit(BackSqirrelKeysCollision, { 217,69 }, { -2,4,0 });
}

void BackSqirrelKey::Update(float _DeltaTime)
{
	duplicationTime += _DeltaTime;
	if (duplicationTime > 0.5f)
	{
		duplication = true;
		duplicationTime = 0.0f;
	}
	ManagedCollision(BackSqirrelKeysCollision, 0);
	if (true == ClickCheck(BackSqirrelKeysCollision))
	{
		Play(Sound, "Squirrel01.wav", 0.1f);
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
	//´Ù¼ö»ý¼ºµÊ
	if (BackSqirrelKeysCollision->Collision(ActorTypeEnum::Nut_Close, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable()
		&& true==duplication)
	{
		Play(Sound, "Squirrel01.wav", 0.1f);
		duplication = false;
		BackSqirrelKeys->ChangeAnimation("ShakeKey");
		GetLevel()->CreateActor<SquirrelCloud_Crack>();
	}
	if (BackSqirrelKeysCollision->Collision(ActorTypeEnum::Nut_Open, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		Play(Sound, "SquirrelEat.wav", 0.1f);
		LevelStateManager::MG->SetIsGetTheKeyTrue();
		BackSqirrelKeys->ChangeAnimation("FallingKey");
	}
	if (BackSqirrelKeys->IsAnimationEnd()
		&& true==LevelStateManager::MG->GetIsGetTheKey())
	{
		GetLevel()->CreateActor<SquirrelKey>();
		Death();
	}
}