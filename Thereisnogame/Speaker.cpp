#include "PrecompileHeader.h"
#include "Speaker.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"


Speaker* Speaker::TM;
Speaker::Speaker()
{
	TM = this;
}

Speaker::~Speaker()
{
}

void Speaker::Start()
{
	float4 Position = float4::Zero;
	Speakers = Init(Speakers, "Speaker_T.png", { 78,70 }, Position);
	SpeakersOff = Init(SpeakersOff, "Speaker_T.png", { 82,75 }, Position);
	SpeakersOff->Off();
	SpeakersCollision = CollisionInit(SpeakersCollision, { 123,171 }, Position);
}


void Speaker::Update(float _DeltaTime)
{
	if (ClickCheck(SpeakersCollision))
	{
		Speakers->Off();
		SpeakersOff->On();
	}
}

void Speaker::Render(float _Delta)
{

};
