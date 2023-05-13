#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle8 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle8();
	~ClockPaddle8();

	// delete Function
	ClockPaddle8(const ClockPaddle8& _Other) = delete;
	ClockPaddle8(ClockPaddle8&& _Other) noexcept = delete;
	ClockPaddle8& operator=(const ClockPaddle8& _Other) = delete;
	ClockPaddle8& operator=(ClockPaddle8&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle8s;

};

