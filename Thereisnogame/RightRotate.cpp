#include "PrecompileHeader.h"
#include "RightRotate.h"

//PlatForm
//Core
//Actor


RightRotate* RightRotate::MainRightRotate;
RightRotate::RightRotate()
{
	MainRightRotate = this;
}

RightRotate::~RightRotate()
{
}

void RightRotate::Start()
{
	RightRotates=Init(RightRotates, "Rotate.png", { 84,72 }, { 430,-10 });
	RightRotatesCollision = CollisionInit(RightRotatesCollision, { 84,72,1 }, { 430,-10 });

	HowManyClick = 0;
}

void RightRotate::Update(float _DeltaTime)
{
	ClearClickValue();
	if (true == ClickCheck(RightRotatesCollision))
	{
		Play(Sound, "Chap02_RotationImage.wav", 0.1f);
		++HowManyClick;
	}
}

void RightRotate::Render(float _Delta)
{

};

void RightRotate::ClearClickValue()
{
	if (HowManyClick >= 4 || HowManyClick <= -4)
	{
		HowManyClick = 0;
	}
}