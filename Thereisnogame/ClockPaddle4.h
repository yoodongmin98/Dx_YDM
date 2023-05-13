#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPaddle4 : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPaddle4();
	~ClockPaddle4();

	// delete Function
	ClockPaddle4(const ClockPaddle4& _Other) = delete;
	ClockPaddle4(ClockPaddle4&& _Other) noexcept = delete;
	ClockPaddle4& operator=(const ClockPaddle4& _Other) = delete;
	ClockPaddle4& operator=(ClockPaddle4&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPaddle4s;

};

