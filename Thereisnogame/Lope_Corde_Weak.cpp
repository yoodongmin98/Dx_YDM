#include "PrecompileHeader.h"
#include "Lope_Corde_Weak.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Play within a play Level.h"

Lope_Corde_Weak::Lope_Corde_Weak()
{
}

Lope_Corde_Weak::~Lope_Corde_Weak()
{
}

void Lope_Corde_Weak::Start()
{
	Lope_Corde_Weaks = Init(Lope_Corde_Weaks, "Corde_Weak.png", { 56,454 }, { 0,0,0 });
}

void Lope_Corde_Weak::Update(float _DeltaTime)
{

}

void Lope_Corde_Weak::Render(float _Delta)
{

};

