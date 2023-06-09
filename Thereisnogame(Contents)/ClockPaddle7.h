#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle7 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle7();
	~ClockPaddle7();

	// delete Function
	ClockPaddle7(const ClockPaddle7& _Other) = delete;
	ClockPaddle7(ClockPaddle7&& _Other) noexcept = delete;
	ClockPaddle7& operator=(const ClockPaddle7& _Other) = delete;
	ClockPaddle7& operator=(ClockPaddle7&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle7s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle7sCollision;

};

