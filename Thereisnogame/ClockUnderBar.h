#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockUnderBar : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockUnderBar();
	~ClockUnderBar();

	// delete Function
	ClockUnderBar(const ClockUnderBar& _Other) = delete;
	ClockUnderBar(ClockUnderBar&& _Other) noexcept = delete;
	ClockUnderBar& operator=(const ClockUnderBar& _Other) = delete;
	ClockUnderBar& operator=(ClockUnderBar&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars;

};

