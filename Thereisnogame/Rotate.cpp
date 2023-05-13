#include "PrecompileHeader.h"
#include "Rotate.h"

//PlatForm
//Core
//Actor



Rotate::Rotate()
{
}

Rotate::~Rotate()
{
}

void Rotate::Start()
{
	LeftRotate=Init(LeftRotate, "Rotate.png", { 84,72 }, float4::Zero);
	RightRotate=Init(RightRotate, "Rotate.png", { 84,72 }, float4::Zero);
}

void Rotate::Update(float _DeltaTime)
{

}

void Rotate::Render(float _Delta)
{

};
