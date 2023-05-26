#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Brazilian : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Brazilian();
	~F_Brazilian();

	// delete Function
	F_Brazilian(const F_Brazilian& _Other) = delete;
	F_Brazilian(F_Brazilian&& _Other) noexcept = delete;
	F_Brazilian& operator=(const F_Brazilian& _Other) = delete;
	F_Brazilian& operator=(F_Brazilian&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Brazilians;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_BraziliansCollision;
};

