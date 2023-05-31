#include "PrecompileHeader.h"
#include "OpeningBackGround.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Play within a play Level.h"

OpeningBackGround::OpeningBackGround()
{
}

OpeningBackGround::~OpeningBackGround()
{
}

void OpeningBackGround::Start()
{
	OpeningBackGrounds = Init(OpeningBackGrounds, "Empty.png", { 1280,720,1 }, { 0,0,0 });
}

void OpeningBackGround::Update(float _DeltaTime)
{

}

void OpeningBackGround::Render(float _Delta)
{

};

