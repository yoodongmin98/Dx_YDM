#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle1 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle1();
	~ClockPaddle1();

	// delete Function
	ClockPaddle1(const ClockPaddle1& _Other) = delete;
	ClockPaddle1(ClockPaddle1&& _Other) noexcept = delete;
	ClockPaddle1& operator=(const ClockPaddle1& _Other) = delete;
	ClockPaddle1& operator=(ClockPaddle1&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle1s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle1sCollision;

};

