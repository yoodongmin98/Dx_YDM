#include "PrecompileHeader.h"
#include "PurpleBox.h"

//PlatForm
//Core
//Actor


PurpleBox::PurpleBox()
{
}

PurpleBox::~PurpleBox()
{
}

void PurpleBox::Start()
{
	PurpleBoxs = Init(PurpleBoxs, "PurpleBox.png", { 580,70.0f }, float4::Down * 270);
}

void PurpleBox::Update(float _DeltaTime)
{

}

void PurpleBox::Render(float _Delta)
{

};
