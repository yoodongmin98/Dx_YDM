#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Chain : public GameEngineActor
{
public:
	// constrcuter destructer

	Chain();
	~Chain();

	// delete Function
	Chain(const Chain& _Other) = delete;
	Chain(Chain&& _Other) noexcept = delete;
	Chain& operator=(const Chain& _Other) = delete;
	Chain& operator=(Chain&& _Other) noexcept = delete;

	void SetChainDeath()
	{
		DeathCheck = true;
	}
	void SetChainLiveTime(float _LiveTime)
	{
		ChainLiveTime = _LiveTime;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftChain;
	std::shared_ptr<class GameEngineSpriteRenderer> RightChain;

	float DeathTime = 0.0f;
	float LerfTime = 0.0f;
	float Speed = 4.0f;
	float ChainLiveTime = 0.0f;

	float4 LStartPos = float4::Zero;
	float4 RStartPos = float4::Zero;
	float4 LEndPos = float4::Zero;
	float4 REndPos = float4::Zero;

	bool DeathCheck = false;
};

