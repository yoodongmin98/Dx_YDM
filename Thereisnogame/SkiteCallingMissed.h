#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SkiteCallingMissed : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteCallingMissed();
	~SkiteCallingMissed();

	// delete Function
	SkiteCallingMissed(const SkiteCallingMissed& _Other) = delete;
	SkiteCallingMissed(SkiteCallingMissed&& _Other) noexcept = delete;
	SkiteCallingMissed& operator=(const SkiteCallingMissed& _Other) = delete;
	SkiteCallingMissed& operator=(SkiteCallingMissed&& _Other) noexcept = delete;

	void FallandDeathCheck();

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteCallingMisseds;
	std::shared_ptr<class GameEngineCollision> SkiteCallingMissedsCollision;

	bool FallStart = false;
};

