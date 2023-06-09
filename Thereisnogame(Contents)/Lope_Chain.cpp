#include "PrecompileHeader.h"
#include "Lope_Chain.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Play within a play Level.h"

Lope_Chain::Lope_Chain()
{
}

Lope_Chain::~Lope_Chain()
{
}

void Lope_Chain::Start()
{
	Lope_Chains = Init(Lope_Chains, "Chaines.png", { 53,420 }, { -300,300,0 });
}

void Lope_Chain::Update(float _DeltaTime)
{

}

void Lope_Chain::Render(float _Delta)
{

};

