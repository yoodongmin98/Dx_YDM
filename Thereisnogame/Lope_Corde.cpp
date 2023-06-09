#include "PrecompileHeader.h"
#include "Lope_Corde.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "LevelStateManager.h"
#include "Mouse.h"
#include "Play within a play Level.h"
#include "Scissor_Fall.h"
Lope_Corde::Lope_Corde()
{
}

Lope_Corde::~Lope_Corde()
{
}

void Lope_Corde::Start()
{
	Lope_Cordes = Init(Lope_Cordes, "Corde.png", { 39,582 }, { 300,300,0 });
	Lope_CordesCollision = CollisionInit(Lope_CordesCollision, { 39,182 }, { 300,100,0 });
}
bool InitBool = true;
void Lope_Corde::Update(float _DeltaTime)
{
	DeathCheck();
	if (true == LevelStateManager::MG->GetIsSlantBoard()&&true== InitBool)
	{
		Lope_Cordes->SetScaleToTexture("Corde_Weak.png");
		Lope_Cordes->GetTransform()->SetLocalScale({ 56,454 });
		Lope_Cordes->GetTransform()->SetLocalPosition(Lope_Cordes->GetTransform()->GetLocalPosition());
		Lope_CordesCollision->GetTransform()->SetLocalPosition(Lope_Cordes->GetTransform()->GetLocalPosition());
		InitBool = false;
	}
}

void Lope_Corde::Render(float _Delta)
{
	
};

void Lope_Corde::DeathCheck()
{
	if (Lope_CordesCollision->Collision(ActorTypeEnum::ScreenActor, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true==Mouse::MainMouse->IsInteractable())
	{
		LevelStateManager::MG->SetIsCutTheLopeTrue();
		GetLevel()->CreateActor<ScissorDeath>();
		Death();
	}
}

