#include "PrecompileHeader.h"
#include "LeftDirectionArrow.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor

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
}
bool BlinkArrowLeftBool = true;
void LeftDirectionArrow::Update(float _DeltaTime)
{
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
