#include "PrecompileHeader.h"
#include "Chain.h"

//Base
#include <GameEngineBase/GameEngineDirectory.h>
//PlatForm
//Core

Chain::Chain()
{

}

Chain::~Chain()
{
}

void Chain::Start()
{
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Animation");
	
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Chain").GetFullPath());
	}
	LeftChain = CreateComponent<GameEngineSpriteRenderer>();
	LeftChain->SetScaleToTexture("BandePellicule0.png");
	LeftChain->GetTransform()->SetLocalScale({121,720});
	LeftChain->GetTransform()->SetLocalPosition({-700,0});//-580
	LeftChain->CreateAnimation("ChainMove","Chain",0.05f);
	LeftChain->ChangeAnimation("ChainMove");

	RightChain = CreateComponent<GameEngineSpriteRenderer>();
	RightChain->SetScaleToTexture("BandePellicule0.png");
	RightChain->GetTransform()->SetLocalScale({ 121,720 });
	RightChain->GetTransform()->SetLocalPosition({ 700,0 });//580
	RightChain->CreateAnimation("ChainMove", "Chain", 0.05f);
	RightChain->ChangeAnimation("ChainMove");
	RightChain->SetFlipX();


	LStartPos = LeftChain->GetTransform()->GetLocalPosition();
	RStartPos = RightChain->GetTransform()->GetLocalPosition();

	LEndPos = LStartPos + float4{ 120,0 };
	REndPos = RStartPos + float4{ -120,0 };
}

void Chain::Update(float _DeltaTime)
{
	if (DeathTime < 2.0f)//ChainLiveTime으로 바꿔야함
	{
		DeathTime += _DeltaTime;
		LerfTime += _DeltaTime * Speed;
		LeftChain->GetTransform()->SetLocalPosition(float4::LerpClamp(LStartPos, LEndPos, LerfTime));
		RightChain->GetTransform()->SetLocalPosition(float4::LerpClamp(RStartPos, REndPos, LerfTime));
	}
	if (DeathTime > 2.0f)
	{
		LerfTime -= _DeltaTime * Speed;
		LeftChain->GetTransform()->SetLocalPosition(float4::LerpClamp(LStartPos, LEndPos, LerfTime));
		RightChain->GetTransform()->SetLocalPosition(float4::LerpClamp(RStartPos, REndPos, LerfTime));
	}
	
	if (GetLiveTime() > 5.0f)
	{
		DeathCheck = true;
	}
	if (true == DeathCheck)
	{
		Death();
	}

}

void Chain::Render(float _Delta)
{

};
