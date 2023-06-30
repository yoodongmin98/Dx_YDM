#include "PrecompileHeader.h"
#include "CoffreFortHandle.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
#include "Play within a play Level.h"

CoffreFortHandle::CoffreFortHandle()
{
}

CoffreFortHandle::~CoffreFortHandle()
{
}

void CoffreFortHandle::Start()
{
	
	float4 Position = { -10,10 };
	CoffreFortHandlesShadow = Init(CoffreFortHandlesShadow, "CoffreFortHandleShadow.png", { 218,218 }, { Position.x ,Position.y-25});
	CoffreFortHandles = Init(CoffreFortHandles, "CoffreFortHandle.png", { 234,234 }, Position);
	CoffreFortHandlesCollision = CollisionInit(CoffreFortHandlesCollision, { 200,200 }, Position);
}

void CoffreFortHandle::Update(float _DeltaTime)
{
	HandleRotateCheck(_DeltaTime);
	HandleCheckNextLevel();
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
		CoffreFortHandlesShadow->GetTransform()->AddLocalRotation({ 0,0,Force * _DeltaTime });
	}
}

void CoffreFortHandle::HandleCheckNextLevel()
{
	if (true == LevelStateManager::MG->GetIsCogStick() && true == LevelStateManager::MG->GetIsRougeStick()
		&&true==ClickCheck(CoffreFortHandlesCollision) &&false==LevelStateManager::MG->GetIsPanelClick())
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::MemorySet);
	}
}

