#include "PrecompileHeader.h"
#include "SkiteCalling.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "Chain.h"
#include "LevelStateManager.h"

SkiteCalling::SkiteCalling()
{
}

SkiteCalling::~SkiteCalling()
{
}

void SkiteCalling::Start()
{
	SkiteCallings=Init(SkiteCallings, "SkiteCalling.png", { 285,407 }, { 0,0,0 });
	SkiteSpeakings = Init(SkiteSpeakings, "SkiteCalling_Speaking.png", { 285,407 }, { 0,0,0 });

	SkiteCallingCollision = CollisionInit(SkiteCallingCollision, { 64,64,1 }, { -55,-110 });

	SkiteCallings->On();
	SkiteSpeakings->Off();
}

void SkiteCalling::Update(float _DeltaTime)
{
	if (true == ClickCheck(SkiteCallingCollision))
	{
		SkiteCallings->Death();
		SkiteSpeakings->On();
		ChainPtr = GetLevel()->CreateActor<Chain>();
		ChainPtr->SetChainLiveTime(LiveTime);
	}
	if (false == LevelStateManager::MG->GetIsProgress()
		&& nullptr != ChainPtr)
	{
		LevelStateManager::MG->MinusCollisionValue();
		Death();
	}
}

void SkiteCalling::Render(float _Delta)
{

};
