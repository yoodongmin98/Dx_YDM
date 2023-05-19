#include "PrecompileHeader.h"
#include "LeftRotate.h"

//PlatForm
//Core
//Actor



LeftRotate::LeftRotate()
{
}

LeftRotate::~LeftRotate()
{
}

void LeftRotate::Start()
{
	LeftRotates=Init(LeftRotates, "Rotate.png", { 84,72 }, { -300,0 });
	LeftRotates->SetFlipX();
}

void LeftRotate::Update(float _DeltaTime)
{

}

void LeftRotate::Render(float _Delta)
{

};
