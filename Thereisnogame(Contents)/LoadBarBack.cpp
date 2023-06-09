#include "PrecompileHeader.h"
#include "LoadBarBack.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core


//Actor


LoadBarBack::LoadBarBack()
{
}

LoadBarBack::~LoadBarBack()
{
}

void LoadBarBack::Start()
{
	LoadBarBacks = Init(LoadBarBacks, "LoadBarBack.png", { 764,119 }, { 0,0,0 });
}

void LoadBarBack::Update(float _DeltaTime)
{

}

void LoadBarBack::Render(float _Delta)
{

};

