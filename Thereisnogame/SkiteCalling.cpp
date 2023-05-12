#include "PrecompileHeader.h"
#include "SkiteCalling.h"

//PlatForm
//Core




SkiteCalling::SkiteCalling()
{
}

SkiteCalling::~SkiteCalling()
{
}

void SkiteCalling::Start()
{
	//Skite_SpeakingÀÌ¶û RenderChange
	SkiteCallings=Init(SkiteCallings, "SkiteCalling.png", { 285,407 }, { 0,0,0 });
	SkiteSpeakings = Init(SkiteSpeakings, "SkiteCalling_Speaking.png", { 285,407 }, { 0,0,0 });

	SkiteCallings->On();
	SkiteSpeakings->Off();
}

void SkiteCalling::Update(float _DeltaTime)
{

}

void SkiteCalling::Render(float _Delta)
{

};
