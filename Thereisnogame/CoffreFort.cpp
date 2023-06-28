#include "PrecompileHeader.h"
#include "CoffreFort.h"
//Base
//PlatForm
//Core
//Actor
CoffreFort::CoffreFort()
{
}

CoffreFort::~CoffreFort()
{
}

void CoffreFort::Start()
{
	CoffreForts = Init(CoffreForts, "CoffreFort.png", { 383,383 }, float4::Zero);
}

void CoffreFort::Update(float _DeltaTime)
{

}

void CoffreFort::Render(float _Delta)
{

};


