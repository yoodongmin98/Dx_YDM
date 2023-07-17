#include "PrecompileHeader.h"
#include "RouageLoad.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"

RouageLoad::RouageLoad()
{
}

RouageLoad::~RouageLoad()
{
}

void RouageLoad::Start()
{
	float4 Position = { -2560 + 30,250 };
	RouageLoads = Init(RouageLoads, "RouageLoad.png", { 109,109 }, Position);
	RouageLoads_overlap = Init(RouageLoads_overlap, "RouageLoad_Overlap.png", { 141,141 }, { Position.x - 3,Position.y + 3 });

	RouageLoadsCollision = CollisionInit(RouageLoadsCollision, { 191,173 }, Position);
	Play(Sound, "Drag1.wav", 0.1f);
}

void RouageLoad::Update(float _DeltaTime)
{
	Fall(RouageLoads, RouageLoads_overlap, RouageLoadsCollision, 55.0f, _DeltaTime);
	CatchCheck(RouageLoads, RouageLoads_overlap, RouageLoadsCollision);
	RougeDeathandInterCheck();
}

void RouageLoad::Render(float _Delta)
{

};

void RouageLoad::RougeDeathandInterCheck()
{
	if (RouageLoadsCollision->Collision(ActorTypeEnum::PanelRouge, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable()
		&& true == LevelStateManager::MG->GetIsPanelClick())
	{
		LevelStateManager::MG->SetIsRougeStickTrue();
		Death();
	}
}
