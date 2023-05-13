#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockNight : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockNight();
	~ClockNight();

	// delete Function
	ClockNight(const ClockNight& _Other) = delete;
	ClockNight(ClockNight&& _Other) noexcept = delete;
	ClockNight& operator=(const ClockNight& _Other) = delete;
	ClockNight& operator=(ClockNight&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockNights;
};

