#include "PrecompileHeader.h"
#include "Binary0.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
Binary0::Binary0()
{
}

Binary0::~Binary0()
{
}

void Binary0::Start()
{
	Binary0s = Init(Binary0s, "FXBinaire0.png", { 14,14 }, StartPosition);
	Binary0s->ColorOptionValue.MulColor.a = 1;
}

void Binary0::Update(float _DeltaTime)
{
	Binary0s->ColorOptionValue.MulColor.a -= 0.001f;
	if (Binary0s->ColorOptionValue.MulColor.a <= 0)
	{
		Death();
	}
	Binary0s->GetTransform()->SetLocalPosition(StartPosition);
	Binary0s->GetTransform()->SetLocalScale(StartScale);
	Binary0Time += _DeltaTime;
	RightFallRigid(RightValue, DownValue, Binarybool, Binary0Time);
}

void Binary0::Render(float _Delta)
{

};
