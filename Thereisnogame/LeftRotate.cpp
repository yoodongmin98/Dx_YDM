#include "PrecompileHeader.h"
#include "LeftRotate.h"

//PlatForm
//Core



//Actor
#include "RightRotate.h"


LeftRotate::LeftRotate()
{
}

LeftRotate::~LeftRotate()
{
}

void LeftRotate::Start()
{
	LeftRotates=Init(LeftRotates, "Rotate.png", { 84,72 }, { -430,-10 });
	LeftRotates->SetFlipX();
	LeftRotatesCollision = CollisionInit(LeftRotatesCollision, { 84,72,1 }, { -430,-10 });
}

void LeftRotate::Update(float _DeltaTime)
{
	if (true == ClickCheck(LeftRotatesCollision))
	{
		Play(Sound, "Chap02_RotationImage.wav", 0.1f);
		RightRotate::MainRightRotate->MinusHowManyClick();
	}
}

void LeftRotate::Render(float _Delta)
{

};
