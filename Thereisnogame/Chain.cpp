#include "PrecompileHeader.h"
#include "Chain.h"

//Base
#include <GameEngineBase/GameEngineDirectory.h>
//PlatForm
//Core

//Actor
#include "LevelStateManager.h"
Chain::Chain()
{

}

Chain::~Chain()
{
}
bool ChainLoad = true;
void Chain::Start()
{
	LevelStateManager::MG->SetIsProgressTrue();
	if(true==ChainLoad)
	{
		AnimationImageLoad("Chain");
		ChainLoad = false;
	}

	LeftChain=AnimationInit(LeftChain, "BandePellicule0.png", { 121,720 }, { -700,0 }, "ChainMove", "Chain",3, 0.05f, true);
	RightChain = AnimationInit(RightChain, "BandePellicule0.png", { 121,720 }, { 700,0 }, "ChainMove", "Chain",3, 0.05f, true);
	RightChain->SetFlipX();

	LStartPos = LeftChain->GetTransform()->GetLocalPosition();
	RStartPos = RightChain->GetTransform()->GetLocalPosition();

	LEndPos = LStartPos + float4{ 120,0 };
	REndPos = RStartPos + float4{ -120,0 };
}

void Chain::Update(float _DeltaTime)
{
	if (DeathTime < ChainLiveTime)//ChainLiveTime으로 바꿔야함
	{
		DeathTime += _DeltaTime;
		LerfTime += _DeltaTime * Speed;
		LeftChain->GetTransform()->SetLocalPosition(float4::LerpClamp(LStartPos, LEndPos, LerfTime));
		RightChain->GetTransform()->SetLocalPosition(float4::LerpClamp(RStartPos, REndPos, LerfTime));
	}
	if (DeathTime > ChainLiveTime)
	{
		LerfTime -= _DeltaTime * Speed;
		LeftChain->GetTransform()->SetLocalPosition(float4::LerpClamp(LStartPos, LEndPos, LerfTime));
		RightChain->GetTransform()->SetLocalPosition(float4::LerpClamp(RStartPos, REndPos, LerfTime));
	}
	
	if (GetLiveTime() > ChainLiveTime*2)
	{
		DeathCheck = true;
	}
	if (true == DeathCheck)
	{
		LevelStateManager::MG->SetIsProgressFalse();
		Death();
	}

}

void Chain::Render(float _Delta)
{

};
