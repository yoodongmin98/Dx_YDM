#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockDay : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockDay();
	~ClockDay();

	// delete Function
	ClockDay(const ClockDay& _Other) = delete;
	ClockDay(ClockDay&& _Other) noexcept = delete;
	ClockDay& operator=(const ClockDay& _Other) = delete;
	ClockDay& operator=(ClockDay&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockDays;
};

