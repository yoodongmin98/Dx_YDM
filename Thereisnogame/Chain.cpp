#include "PrecompileHeader.h"
//#include <GameEngineBase/GameEngineDirectory.h>
//
//#include <GameEnginePlatform/GameEngineInput.h>
//
//
//#include <GameEngineCore/GameEngineActor.h>
//
//#include <GameEngineCore/GameEngineLevel.h>
//#include <GameEngineCore/GameEngineCollision.h>
//#include <GameEnginePlatform/GameEngineWindow.h>
//
//
//
//
//#include "Chain.h"
//
//
//Chain::Chain()
//{
//}
//
//Chain::~Chain()
//{
//}
//
//void Chain::Start()
//{
//	ChainRender = CreateRender("Chain.bmp", TestOrder::Chain);
//	ChainRender->SetPosition({ 0,GameEngineWindow::GetScreenSize().half().y });
//	ChainRender->EffectCameraOff();
//	ChainRender->CreateAnimation({ .AnimationName = "ChainStart",  .ImageName = "Chain.bmp", .Start = 0, .End = 3, .InterTime = 0.05f});
//	ChainRender->SetScale({ 200, 720 });
//	ChainRender->EffectCameraOff();
//
//
//}
//void Chain::Update(float _DeltaTime)
//{
//	if (Deathtime < 2.0f)
//	{
//		LerfTime += _DeltaTime * Speed;
//		Deathtime += _DeltaTime;
//		ChainRender->ChangeAnimation("ChainStart");
//		SetPos(float4::LerpClamp(StartPos, EndPos, LerfTime));
//	}
//	
//	if (Deathtime > 2.0f)
//	{
//		LerfTime -= _DeltaTime * Speed;
//		SetPos(float4::LerpClamp(StartPos, EndPos, LerfTime));
//		if (GetPos().x <= (-100.0f)||GetPos().x>=1400.0f)
//		{
//			Death();
//		}
//	}
//	
//}
//void Chain::Render(float _Time)
//{
//
//}
//
