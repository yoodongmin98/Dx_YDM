#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_PR_Super : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_PR_Super();
	~BoxCroix_PR_Super();

	// delete Function
	BoxCroix_PR_Super(const BoxCroix_PR_Super& _Other) = delete;
	BoxCroix_PR_Super(BoxCroix_PR_Super&& _Other) noexcept = delete;
	BoxCroix_PR_Super& operator=(const BoxCroix_PR_Super& _Other) = delete;
	BoxCroix_PR_Super& operator=(BoxCroix_PR_Super&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

