#include "PrecompileHeader.h"
#include "CoffreFortHandle.h"
//Base
//PlatForm
//Core
//Actor
CoffreFortHandle::CoffreFortHandle()
{
}

CoffreFortHandle::~CoffreFortHandle()
{
}

void CoffreFortHandle::Start()
{
	CoffreFortHandles = Init(CoffreFortHandles, "CoffreFortHandle.png", { 234,234 }, float4::Zero);
}

void CoffreFortHandle::Update(float _DeltaTime)
{

}

void CoffreFortHandle::Render(float _Delta)
{

};

