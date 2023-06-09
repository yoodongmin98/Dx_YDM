#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle5 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle5();
	~ClockPaddle5();

	// delete Function
	ClockPaddle5(const ClockPaddle5& _Other) = delete;
	ClockPaddle5(ClockPaddle5&& _Other) noexcept = delete;
	ClockPaddle5& operator=(const ClockPaddle5& _Other) = delete;
	ClockPaddle5& operator=(ClockPaddle5&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle5s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle5sCollision;

};

