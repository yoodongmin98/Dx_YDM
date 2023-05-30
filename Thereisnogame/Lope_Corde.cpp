#include "PrecompileHeader.h"
#include "Lope_Corde.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Play within a play Level.h"

Lope_Corde::Lope_Corde()
{
}

Lope_Corde::~Lope_Corde()
{
}

void Lope_Corde::Start()
{
	Lope_Cordes = Init(Lope_Cordes, "Corde.png", { 39,582 }, { 300,300,0 });
}

void Lope_Corde::Update(float _DeltaTime)
{

}

void Lope_Corde::Render(float _Delta)
{

};

