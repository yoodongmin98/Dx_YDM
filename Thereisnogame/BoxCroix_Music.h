#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_Music : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_Music();
	~BoxCroix_Music();

	// delete Function
	BoxCroix_Music(const BoxCroix_Music& _Other) = delete;
	BoxCroix_Music(BoxCroix_Music&& _Other) noexcept = delete;
	BoxCroix_Music& operator=(const BoxCroix_Music& _Other) = delete;
	BoxCroix_Music& operator=(BoxCroix_Music&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

