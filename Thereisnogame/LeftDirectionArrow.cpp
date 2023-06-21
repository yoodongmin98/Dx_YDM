#include "PrecompileHeader.h"
#include "LeftDirectionArrow.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"

LeftDirectionArrow::LeftDirectionArrow()
{
}

LeftDirectionArrow::~LeftDirectionArrow()
{
}

void LeftDirectionArrow::Start()
{
	LeftDirectionArrows = Init(LeftDirectionArrows, "Chap04_ArrowLeft.png", { 99,99 }, float4::Zero);
	LeftDirectionArrowsCollision = CollisionInit(LeftDirectionArrowsCollision, { 99,99 }, float4::Zero);
	LeftDirectionArrows->ColorOptionValue.MulColor.a = 1;
	Cameras = GetLevel()->GetMainCamera()->GetTransform();
}
bool BlinkArrowLeftBool = true;

void LeftDirectionArrow::Update(float _DeltaTime)
{
	CameraMoveCheck(_DeltaTime);
	BlinkArrow();
}

void LeftDirectionArrow::Render(float _Delta)
{

};

void LeftDirectionArrow::BlinkArrow()
{
	if (LeftDirectionArrows->ColorOptionValue.MulColor.a > 0.0f
		&& true == BlinkArrowLeftBool)
	{
		LeftDirectionArrows->ColorOptionValue.MulColor.a -= 0.02f;
	}
	else if (LeftDirectionArrows->ColorOptionValue.MulColor.a < 1.0f
		&& false == BlinkArrowLeftBool)
	{
		LeftDirectionArrows->ColorOptionValue.MulColor.a += 0.02f;
	}
	if (LeftDirectionArrows->ColorOptionValue.MulColor.a <= 0)
	{
		BlinkArrowLeftBool = false;
	}
	if (LeftDirectionArrows->ColorOptionValue.MulColor.a >= 1.0f)
	{
		BlinkArrowLeftBool = true;
	}
}

void LeftDirectionArrow::CameraMoveCheck(float _DeltaTime)
{
	if (true == ClickCheck(LeftDirectionArrowsCollision)
		&&true==LevelStateManager::MG->GetIsCameraMoveCheck()
		&&true== LeftCameraMoveBool)
	{
		LeftCameraMoveBool = false;
		LevelStateManager::MG->SetIsCameraMoveCheckFalse();
		LevelStateManager::MG->SetCameraMoveValueMinus();
		MoveTime = 0.0f;
		StartCameraPos = Cameras->GetLocalPosition();
		EndCameraPos = StartCameraPos - float4{1280.0f, 0, 0};
	}
	if (false == LevelStateManager::MG->GetIsCameraMoveCheck()
		&&false== LeftCameraMoveBool)
	{
		MoveTime += _DeltaTime;
		Cameras->SetLocalPosition(float4::LerpClamp(StartCameraPos, EndCameraPos, MoveTime));
		if (Cameras->GetLocalPosition().x < (LevelStateManager::MG->GetCameraMoveValue() * 1279.0f))
		{			
			LeftCameraMoveBool = true;
			LevelStateManager::MG->SetIsCameraMoveCheckTrue();
		}
	}
}
