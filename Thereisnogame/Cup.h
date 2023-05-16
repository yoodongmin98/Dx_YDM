#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// Ό³Έν :
class Cup : public S_ActorBase
{
public:
	// constrcuter destructer
	Cup();
	~Cup();

	// delete Function
	Cup(const Cup& _Other) = delete;
	Cup(Cup&& _Other) noexcept = delete;
	Cup& operator=(const Cup& _Other) = delete;
	Cup& operator=(Cup&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cups;
	std::shared_ptr<class GameEngineSpriteRenderer> Cups_Overlap;

	std::shared_ptr<class GameEngineCollision> CupCollision;
};

