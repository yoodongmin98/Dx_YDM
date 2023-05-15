#include "PrecompileHeader.h"
#include "Cup.h"

//PlatForm
//Core



Cup::Cup()
{
}

Cup::~Cup()
{
}

void Cup::Start()
{
	//Render2°³
	Cups = Init(Cups, "CupObj_Empty.png", { 94,121 }, {300,0,0});
}

void Cup::Update(float _DeltaTime)
{
	Fall(Cups,60.5f,_DeltaTime);
	CatchCheck(Cups);
}

void Cup::Render(float _Delta)
{

};
