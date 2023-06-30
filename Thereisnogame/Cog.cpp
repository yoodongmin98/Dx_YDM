#include "PrecompileHeader.h"
#include "Cog.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

//Actor
#include "Mouse.h"
#include "LevelStateManager.h"

Cog::Cog()
{
}

Cog::~Cog()
{
}

void Cog::Start()
{
	float4 Position = { -1280,0,0 };
	Cogs_Overlap = Init(Cogs_Overlap, "Cog_OBJ_Overlap.png", { 220,216 }, { Position.x - 3,Position.y + 3 });
	Cogs = Init(Cogs, "Cog_OBJ.png", { 190,184 }, Position);
	CogCollision = CollisionInit(CogCollision, { 190,184,1 }, Position);
}

void Cog::Update(float _DeltaTime)
{
	CatchCheck(Cogs, Cogs_Overlap, CogCollision);
	Fall(Cogs, Cogs_Overlap, CogCollision, 92.0f, _DeltaTime);
	CogDeathandInterCheck();
}

void Cog::Render(float _Delta)
{

};


void Cog::CogDeathandInterCheck()
{
	if (CogCollision->Collision(ActorTypeEnum::PanelCog, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{

	}
}
