#include "PrecompileHeader.h"
#include "LoadErrorPaper.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core


//Actor


LoadErrorPaper::LoadErrorPaper()
{
}

LoadErrorPaper::~LoadErrorPaper()
{
}

void LoadErrorPaper::Start()
{
	LoadErrorPapers = Init(LoadErrorPapers, "LoadErrorPaper.png", { 789,288 }, { 0,0,0 });
}

void LoadErrorPaper::Update(float _DeltaTime)
{

}

void LoadErrorPaper::Render(float _Delta)
{

};

