#include "PrecompileHeader.h"
#include "Binary1.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
Binary1::Binary1()
{
}

Binary1::~Binary1()
{
}

void Binary1::Start()
{
	Binary1s = Init(Binary1s, "FXBinaire1.png", { 14,14 }, float4::Zero);
	Binary1s->ColorOptionValue.MulColor.a = 1;
}

void Binary1::Update(float _DeltaTime)
{
	Binary1s->ColorOptionValue.MulColor.a -= 0.001f;
	if (Binary1s->ColorOptionValue.MulColor.a <= 0)
	{
		Death();
	}
	Binary1s->GetTransform()->SetLocalPosition(StartPosition);
	Binary1s->GetTransform()->SetLocalScale(StartScale);
	Binary1Time += _DeltaTime;
	RightFallRigid(RightValue, DownValue, Binarybool, Binary1Time);
}

void Binary1::Render(float _Delta)
{

};
