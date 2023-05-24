#include "PrecompileHeader.h"
#include "PinBall_Icon.h"

//PlatForm
//Core

//Actor
#include "ColManager.h"

PinBall_Icon::PinBall_Icon()
{
}

PinBall_Icon::~PinBall_Icon()
{
}

void PinBall_Icon::Start()
{
	PinBall_Icons = Init(PinBall_Icons, "Pinball.png", { 75,75 }, {-330,20,0});
}

void PinBall_Icon::Update(float _DeltaTime)
{

}

void PinBall_Icon::Render(float _Delta)
{

};
