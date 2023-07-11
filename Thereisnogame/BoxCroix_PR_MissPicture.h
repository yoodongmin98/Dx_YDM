#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_PR_MissPicture : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_PR_MissPicture();
	~BoxCroix_PR_MissPicture();

	// delete Function
	BoxCroix_PR_MissPicture(const BoxCroix_PR_MissPicture& _Other) = delete;
	BoxCroix_PR_MissPicture(BoxCroix_PR_MissPicture&& _Other) noexcept = delete;
	BoxCroix_PR_MissPicture& operator=(const BoxCroix_PR_MissPicture& _Other) = delete;
	BoxCroix_PR_MissPicture& operator=(BoxCroix_PR_MissPicture&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

