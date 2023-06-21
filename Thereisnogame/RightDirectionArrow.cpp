#include "PrecompileHeader.h"
#include "RightDirectionArrow.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor

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
}
bool BlinkArrowBool = true;
void RightDirectionArrow::Update(float _DeltaTime)
{
	BlinkArrow();
}

void RightDirectionArrow::Render(float _Delta)
{

};

void RightDirectionArrow::BlinkArrow()
{
	if (RightDirectionArrows->ColorOptionValue.MulColor.a > 0.0f
		&& true == BlinkArrowBool)
	{
		RightDirectionArrows->ColorOptionValue.MulColor.a -= 0.02f;
		if (RightDirectionArrows->ColorOptionValue.MulColor.a <= 0)
		{
			BlinkArrowBool = false;
		}
	}
	else if (RightDirectionArrows->ColorOptionValue.MulColor.a < 1.0f
		&&false== BlinkArrowBool)
	{
		RightDirectionArrows->ColorOptionValue.MulColor.a += 0.02f;
		if (RightDirectionArrows->ColorOptionValue.MulColor.a >= 1.0f)
		{
			BlinkArrowBool = true;
		}
	}
}