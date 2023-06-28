#include "PrecompileHeader.h"
#include "CoffreFortHandle.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
//Actor
#include "Mouse.h"

CoffreFortHandle::CoffreFortHandle()
{
}

CoffreFortHandle::~CoffreFortHandle()
{
}

void CoffreFortHandle::Start()
{
	CoffreFortHandles = Init(CoffreFortHandles, "CoffreFortHandle.png", { 234,234 }, float4::Zero);
	CoffreFortHandlesCollision = CollisionInit(CoffreFortHandlesCollision, { 200,200 }, float4::Zero);
}

void CoffreFortHandle::Update(float _DeltaTime)
{
	HandleRotateCheck(_DeltaTime);
}

void CoffreFortHandle::Render(float _Delta)
{

};

void CoffreFortHandle::HandleRotateCheck(float _DeltaTime)
{
	if (CoffreFortHandlesCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& false==Mouse::MainMouse->IsInteractable())
	{
		Force = 400.0f;
	}
	Force -= _DeltaTime*150.0f;
	if(Force>0.0f)
	{ 
		CoffreFortHandles->GetTransform()->AddLocalRotation({ 0,0,Force * _DeltaTime });
	}
}

