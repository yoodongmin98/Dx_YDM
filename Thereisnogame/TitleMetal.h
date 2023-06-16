#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

class TitleMetal : public S_ActorBase
{
public:
	static TitleMetal* TM;
	TitleMetal();
	~TitleMetal();

	TitleMetal(const TitleMetal& _Other) = delete;
	TitleMetal(TitleMetal&& _Other) noexcept = delete;
	TitleMetal& operator=(const TitleMetal& _Other) = delete;
	TitleMetal& operator=(TitleMetal&& _Other) noexcept = delete;

	void SetCreatePosition(float4 _Position)
	{
		CreatePosition = _Position;
	}
	int GetSpeakerCount()
	{
		return SpeakerCount;
	}
	void FallCountCheck();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TitleMetals;
	std::shared_ptr<class GameEngineSpriteRenderer> TitleMetals_overlap;
	std::shared_ptr<class GameEngineCollision> TitleMetalsCollision;

	std::shared_ptr<class GameEngineCollision> FallCheckCollision;

	float4 CreatePosition = float4::Zero;
	int SpeakerCount = 0;
};

