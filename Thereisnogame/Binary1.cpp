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
}

void Binary1::Update(float _DeltaTime)
{
	
}

void Binary1::Render(float _Delta)
{

};
