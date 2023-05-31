#include "PrecompileHeader.h"
#include "MadeWithUnity.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Play within a play Level.h"

MadeWithUnity::MadeWithUnity()
{
}

MadeWithUnity::~MadeWithUnity()
{
}

void MadeWithUnity::Start()
{
	MadeWithUnitys = Init(MadeWithUnitys, "UnitySplash-cube.png", { 1024,512 }, { 0,0,0 });
}

void MadeWithUnity::Update(float _DeltaTime)
{

}

void MadeWithUnity::Render(float _Delta)
{

};

