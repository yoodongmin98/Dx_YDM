#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle2 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle2();
	~ClockPaddle2();

	// delete Function
	ClockPaddle2(const ClockPaddle2& _Other) = delete;
	ClockPaddle2(ClockPaddle2&& _Other) noexcept = delete;
	ClockPaddle2& operator=(const ClockPaddle2& _Other) = delete;
	ClockPaddle2& operator=(ClockPaddle2&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle2s;
	std::shared_ptr<class GameEngineCollision> ClockPaddle2sCollision;

};

