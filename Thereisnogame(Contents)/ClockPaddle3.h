#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle3 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle3();
	~ClockPaddle3();

	// delete Function
	ClockPaddle3(const ClockPaddle3& _Other) = delete;
	ClockPaddle3(ClockPaddle3&& _Other) noexcept = delete;
	ClockPaddle3& operator=(const ClockPaddle3& _Other) = delete;
	ClockPaddle3& operator=(ClockPaddle3&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle3s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle3sCollision;
};

