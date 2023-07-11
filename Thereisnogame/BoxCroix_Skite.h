#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_Skite : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_Skite();
	~BoxCroix_Skite();

	// delete Function
	BoxCroix_Skite(const BoxCroix_Skite& _Other) = delete;
	BoxCroix_Skite(BoxCroix_Skite&& _Other) noexcept = delete;
	BoxCroix_Skite& operator=(const BoxCroix_Skite& _Other) = delete;
	BoxCroix_Skite& operator=(BoxCroix_Skite&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

