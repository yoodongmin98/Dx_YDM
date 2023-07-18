#include "PrecompileHeader.h"
#include "SquirrelKey.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Mouse.h"
#include "SquirrelKeyMiddle.h"
#include "LevelStateManager.h"

SquirrelKey::SquirrelKey()
{
}

SquirrelKey::~SquirrelKey()
{
}

void SquirrelKey::Start()
{
	SquirrelKeyBig = Init(SquirrelKeyBig, "SquirrelKey_Key.png",{177, 187}, float4::Zero);
	SquirrelKeyBig_overlap = Init(SquirrelKeyBig, "SquirrelKey_Key_Overlap.png", { 200, 215 }, float4::Zero);

	SquirrelKeyBigCollision = CollisionInit(SquirrelKeyBigCollision, { 177, 187 }, float4::Zero);
}

void SquirrelKey::Update(float _DeltaTime)
{
	Fall(SquirrelKeyBig, SquirrelKeyBig_overlap, SquirrelKeyBigCollision, 93.5f, _DeltaTime);
	CatchCheck(SquirrelKeyBig, SquirrelKeyBig_overlap, SquirrelKeyBigCollision);
	CollisionInteractableCheck();
	SoundCheck(_DeltaTime);
}

void SquirrelKey::Render(float _Delta)
{

};
bool KeyMiddle = false;
void SquirrelKey::CollisionInteractableCheck()
{
	if (SquirrelKeyBigCollision->Collision(ActorTypeEnum::ZipWip, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true==Mouse::MainMouse->IsInteractable())
	{
		if (false == KeyMiddle)
		{
			Play(Sound, "Zipping.wav", 0.1f);
			GetLevel()->CreateActor<SquirrelKeyMiddle>();
			KeyMiddle = true;
			Death();
		}
	}
}

void SquirrelKey::SoundCheck(float _DeltaTime)
{
	static bool IsPlay = false;
	BoolTime += _DeltaTime;
	if (BoolTime > 1.0f)
	{
		BoolTime = 0.0f;
		IsPlay = false;
	}
	if (SquirrelKeyBigCollision->Collision(ActorTypeEnum::LockFolder, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		LevelStateManager::MG->SetIsLockFolderTouchTrue();
		if (false == IsPlay)
		{
			Play(Sound, "KeysToBig.wav", 0.1f);
			IsPlay = true;
		}
	}
}
