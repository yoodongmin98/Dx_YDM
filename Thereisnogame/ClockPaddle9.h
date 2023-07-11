#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle9 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle9();
	~ClockPaddle9();

	// delete Function
	ClockPaddle9(const ClockPaddle9& _Other) = delete;
	ClockPaddle9(ClockPaddle9&& _Other) noexcept = delete;
	ClockPaddle9& operator=(const ClockPaddle9& _Other) = delete;
	ClockPaddle9& operator=(ClockPaddle9&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle9s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle9sCollision;

};

