#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_PR_18 : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_PR_18();
	~BoxCroix_PR_18();

	// delete Function
	BoxCroix_PR_18(const BoxCroix_PR_18& _Other) = delete;
	BoxCroix_PR_18(BoxCroix_PR_18&& _Other) noexcept = delete;
	BoxCroix_PR_18& operator=(const BoxCroix_PR_18& _Other) = delete;
	BoxCroix_PR_18& operator=(BoxCroix_PR_18&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

