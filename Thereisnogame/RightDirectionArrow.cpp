#include "PrecompileHeader.h"
#include "RightDirectionArrow.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"

RightDirectionArrow::RightDirectionArrow()
{
}

RightDirectionArrow::~RightDirectionArrow()
{
}

void RightDirectionArrow::Start()
{
	RightDirectionArrows = Init(RightDirectionArrows, "Chap04_ArrowRight.png", { 99,99 }, float4::Zero);
	RightDirectionArrowsCollision = CollisionInit(RightDirectionArrowsCollision, { 99,99 }, float4::Zero);
	RightDirectionArrows->ColorOptionValue.MulColor.a = 1;
	Cameras = GetLevel()->GetMainCamera()->GetTransform();
}
bool BlinkArrowBool = true;
void RightDirectionArrow::Update(float _DeltaTime)
{
	CameraMoveCheck(_DeltaTime);
	BlinkArrow(_DeltaTime);
	SoundAndText(_DeltaTime);
}

void RightDirectionArrow::Render(float _Delta)
{

};

void RightDirectionArrow::BlinkArrow(float _DeltaTime)
{
	RightDirectionArrows->ColorOptionValue.MulColor.a=sinf(GetLiveTime()*2.0f) * 0.5f + 0.5f;
}

void RightDirectionArrow::CameraMoveCheck(float _DeltaTime)
{
	if (true == ClickCheck(RightDirectionArrowsCollision)
		&& true == LevelStateManager::MG->GetIsCameraMoveCheck()
		&& true == RightCameraMoveBool)
	{
		Sound = Play(Sound, "SwapScreen.wav",0.1f);
		RightCameraMoveBool = false;
		LevelStateManager::MG->SetIsCameraMoveCheckFalse();
		LevelStateManager::MG->SetCameraMoveValuePlus();
		MoveTime = 0.0f;
		StartCameraPos = Cameras->GetLocalPosition();
		EndCameraPos = StartCameraPos + float4{ 1280.0f, 0, 0 };
	}
	if (false == LevelStateManager::MG->GetIsCameraMoveCheck()
		&& false == RightCameraMoveBool)
	{
		MoveTime += _DeltaTime;
		Cameras->SetLocalPosition(float4::LerpClamp(StartCameraPos, EndCameraPos, MoveTime*1.5f));
		if (Cameras->GetLocalPosition().x >= (LevelStateManager::MG->GetCameraMoveValue() * 1280.0f))
		{
			RightCameraMoveBool = true;
			LevelStateManager::MG->SetIsCameraMoveCheckTrue();
		}
	}
}


void RightDirectionArrow::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	if (SoundTime > 1.0f)
	{
		static bool Play72 = true;
		if (true == Play72)
		{
			Sound = PlaywithinaplayLevel::LM->ChangeMainSound("Chap01Navigation01.wav");
			Play72 = false;
		}
		Font = NFontCreate(Font, "좀 나가라고요!", GetTransform(), 2.0f);
	}

	if (SoundTime > 3.5f)
	{
		static bool Play73 = true;
		if (true == Play73)
		{
			Sound = PlaywithinaplayLevel::LM->ChangeMainSound("Chap01Navigation02.wav");
			Play73 = false;
		}
		Font2 = NFontCreate(Font2, "여긴 개인 공간이에요! 무대 뒤라고요!", GetTransform(), 2.0f);
	}

	if (SoundTime > 6.0f)
	{
		static bool Play74 = true;
		if (true == Play74)
		{
			Sound = PlaywithinaplayLevel::LM->ChangeMainSound("Chap01Navigation03.wav");
			Play74 = false;
		}
		Font3 = NFontCreate(Font3, "여기 오면 안 돼요. 감기 걸릴 거예요.", GetTransform(), 2.0f);
	}
}