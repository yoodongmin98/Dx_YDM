#include "PrecompileHeader.h"
#include "LoadBarTXT.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core

//Actor


LoadBarTXT::LoadBarTXT()
{
}

LoadBarTXT::~LoadBarTXT()
{
}

void LoadBarTXT::Start()
{
	LoadBarTXTs = Init(LoadBarTXTs, "LoadBarTXT.png", { 384,60 }, { 0,0,0 });
}

void LoadBarTXT::Update(float _DeltaTime)
{

}

void LoadBarTXT::Render(float _Delta)
{

};

