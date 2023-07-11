#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_PR_Miss : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_PR_Miss();
	~BoxCroix_PR_Miss();

	// delete Function
	BoxCroix_PR_Miss(const BoxCroix_PR_Miss& _Other) = delete;
	BoxCroix_PR_Miss(BoxCroix_PR_Miss&& _Other) noexcept = delete;
	BoxCroix_PR_Miss& operator=(const BoxCroix_PR_Miss& _Other) = delete;
	BoxCroix_PR_Miss& operator=(BoxCroix_PR_Miss&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

