#include "PrecompileHeader.h"
#include "FlagChain_Back.h"
//Base
//PlatForm
//Core
//Actor
FlagChain_Back::FlagChain_Back()
{
}

FlagChain_Back::~FlagChain_Back()
{
}

void FlagChain_Back::Start()
{
	FlagChain_Backs = Init(FlagChain_Backs, "FlagChaineAvantPlan.png", { 375,855 }, { -3100,-50});
	FlagChain_Backs->GetTransform()->AddLocalRotation({0,0,30});
}

void FlagChain_Back::Update(float _DeltaTime)
{

}

void FlagChain_Back::Render(float _Delta)
{

};
