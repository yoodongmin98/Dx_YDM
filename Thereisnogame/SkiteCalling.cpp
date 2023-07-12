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
	Sound=Play(Sound, "SkiteRing.wav", 0.1f);
	Sound.SetLoop(-1);

	Font1 = FontCreate(Font1, 23, "전화 받는 중...", { 0,190,0 }, GetTransform(), 2);
	Font2 = FontCreate(Font2, 23, "통화 중...", { 0,190,0 }, GetTransform(), 2);
	Font2->Off();
	Font3 = FontCreate(Font3, 30, "나아님", { 0,-10,0 }, GetTransform(), 2);
}

void SkiteCalling::Update(float _DeltaTime)
{
	if (true == ClickCheck(SkiteCallingCollision))
	{
		Sound2 = Play(Sound2, "CallingClick.wav", 0.1f);
		Font1->Death();
		Font2->On();
		Sound.Stop();
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
