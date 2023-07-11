#include "PrecompileHeader.h"
#include "Cup_Full.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core


//Actor
#include "Mouse.h"
#include "LevelStateManager.h"

Cup_Full::Cup_Full()
{
}

Cup_Full::~Cup_Full()
{
}

void Cup_Full::Start()
{
	float4 Position = Mouse::MainMouse->GetMousePos();
	Cup_Fulls = Init(Cup_Fulls, "CupObj_Full.png", { 94,121 }, Position);
	Cup_Fulls_overlap = Init(Cup_Fulls_overlap, "CupObj_Full_Overlap.png", { 126,153 }, { Position.x - 3,Position.y + 3 });
	
	Cup_FullsCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Cup_Full);
	Cup_FullsCollision->GetTransform()->SetLocalScale({ 94,121,1 });
	Cup_FullsCollision->GetTransform()->SetLocalPosition(Position);

	Play(Sound, "CupFull.wav", 0.2f);
}

void Cup_Full::Update(float _DeltaTime)
{
	Fall(Cup_Fulls, Cup_Fulls_overlap, Cup_FullsCollision, 60.5f, _DeltaTime);
	CatchCheck(Cup_Fulls, Cup_Fulls_overlap, Cup_FullsCollision);
	if (true == LevelStateManager::MG->GetIsBigTree())
	{
		Death();
	}
}

void Cup_Full::Render(float _Delta)
{

};
