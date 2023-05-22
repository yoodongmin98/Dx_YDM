#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockDayandNight : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockDayandNight();
	~ClockDayandNight();

	// delete Function
	ClockDayandNight(const ClockDayandNight& _Other) = delete;
	ClockDayandNight(ClockDayandNight&& _Other) noexcept = delete;
	ClockDayandNight& operator=(const ClockDayandNight& _Other) = delete;
	ClockDayandNight& operator=(ClockDayandNight&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockDay;
	std::shared_ptr<class GameEngineSpriteRenderer> ClockNight;

};

