#include "PrecompileHeader.h"
#include "BoxCroix.h"

//PlatForm
//Core

BoxCroix::BoxCroix()
{

}

BoxCroix::BoxCroix(float4 _Position)
	: Position(_Position)
{
}

BoxCroix::~BoxCroix()
{
}

void BoxCroix::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, Position);
}

void BoxCroix::Update(float _DeltaTime)
{

}

void BoxCroix::Render(float _Delta)
{

};
