#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_German: public G_ActorBase
{
public:
	// constrcuter destructer
	F_German();
	~F_German();

	// delete Function
	F_German(const F_German& _Other) = delete;
	F_German(F_German&& _Other) noexcept = delete;
	F_German& operator=(const F_German& _Other) = delete;
	F_German& operator=(F_German&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Germans;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_GermansCollision;
};

