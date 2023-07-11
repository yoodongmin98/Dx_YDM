#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_ClockDay : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_ClockDay();
	~BoxCroix_ClockDay();

	// delete Function
	BoxCroix_ClockDay(const BoxCroix_ClockDay& _Other) = delete;
	BoxCroix_ClockDay(BoxCroix_ClockDay&& _Other) noexcept = delete;
	BoxCroix_ClockDay& operator=(const BoxCroix_ClockDay& _Other) = delete;
	BoxCroix_ClockDay& operator=(BoxCroix_ClockDay&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

