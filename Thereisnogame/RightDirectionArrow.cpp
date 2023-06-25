#include "PrecompileHeader.h"
#include "RightDirectionArrow.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"

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