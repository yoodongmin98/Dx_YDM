#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle6 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle6();
	~ClockPaddle6();

	// delete Function
	ClockPaddle6(const ClockPaddle6& _Other) = delete;
	ClockPaddle6(ClockPaddle6&& _Other) noexcept = delete;
	ClockPaddle6& operator=(const ClockPaddle6& _Other) = delete;
	ClockPaddle6& operator=(ClockPaddle6&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle6s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle6sCollision;

};

