//#pragma once
//#include <GameEngineCore/GameEngineActor.h>
//#include <GameEnginePlatform/GameEngineImage.h>
//
//
//class Chain : public GameEngineActor
//{
//public:
//
//	Chain();
//	~Chain();
//
//
//	Chain(const Chain& _Other) = delete;
//	Chain(Chain&& _Other) noexcept = delete;
//	Chain& operator=(const Chain& _Other) = delete;
//	Chain& operator=(Chain&& _Other) noexcept = delete;
//
//	void SetChainPos(float4 _StartPos,float4 _EndPos)
//	{
//		StartPos = { _StartPos };
//		EndPos = { _EndPos };
//	}
//
//protected:
//	void Start() override;
//	void Update(float _DeltaTime) override;
//	void Render(float _Time) override;
//
//private:
//	GameEngineRender* ChainRender = nullptr;
//
//	float LerfTime = 0.0f;
//	float Deathtime = 0.0f;
//
//	float Speed = 4.0f;
//
//	float4 StartPos = float4::Zero;
//	float4 EndPos = float4::Zero;
//};
//
