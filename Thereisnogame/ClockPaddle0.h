#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle0 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle0();
	~ClockPaddle0();

	// delete Function
	ClockPaddle0(const ClockPaddle0& _Other) = delete;
	ClockPaddle0(ClockPaddle0&& _Other) noexcept = delete;
	ClockPaddle0& operator=(const ClockPaddle0& _Other) = delete;
	ClockPaddle0& operator=(ClockPaddle0&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle0s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle0sCollision;

};

