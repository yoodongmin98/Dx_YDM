#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Russian : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Russian();
	~F_Russian();

	// delete Function
	F_Russian(const F_Russian& _Other) = delete;
	F_Russian(F_Russian&& _Other) noexcept = delete;
	F_Russian& operator=(const F_Russian& _Other) = delete;
	F_Russian& operator=(F_Russian&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Russians;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_RussiansCollision;
};

