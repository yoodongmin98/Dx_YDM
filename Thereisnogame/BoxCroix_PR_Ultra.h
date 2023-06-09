#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_PR_Ultra : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_PR_Ultra();
	~BoxCroix_PR_Ultra();

	// delete Function
	BoxCroix_PR_Ultra(const BoxCroix_PR_Ultra& _Other) = delete;
	BoxCroix_PR_Ultra(BoxCroix_PR_Ultra&& _Other) noexcept = delete;
	BoxCroix_PR_Ultra& operator=(const BoxCroix_PR_Ultra& _Other) = delete;
	BoxCroix_PR_Ultra& operator=(BoxCroix_PR_Ultra&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

