#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

class Scissor : public S_ActorBase
{
public:
	Scissor();
	~Scissor();

	Scissor(const Scissor& _Other) = delete;
	Scissor(Scissor&& _Other) noexcept = delete;
	Scissor& operator=(const Scissor& _Other) = delete;
	Scissor& operator=(Scissor&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Scissors;
	std::shared_ptr<class GameEngineSpriteRenderer> Scissors_overlap;
	std::shared_ptr<class GameEngineSpriteRenderer> Scissors_Cut;
	std::shared_ptr<class GameEngineCollision> ScissorsCollision;
};

