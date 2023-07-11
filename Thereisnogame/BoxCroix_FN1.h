#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_FN1 : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_FN1();
	~BoxCroix_FN1();

	// delete Function
	BoxCroix_FN1(const BoxCroix_FN1& _Other) = delete;
	BoxCroix_FN1(BoxCroix_FN1&& _Other) noexcept = delete;
	BoxCroix_FN1& operator=(const BoxCroix_FN1& _Other) = delete;
	BoxCroix_FN1& operator=(BoxCroix_FN1&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

