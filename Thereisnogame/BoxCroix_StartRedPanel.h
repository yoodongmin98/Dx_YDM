#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_StartRedPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_StartRedPanel();
	~BoxCroix_StartRedPanel();

	// delete Function
	BoxCroix_StartRedPanel(const BoxCroix_StartRedPanel& _Other) = delete;
	BoxCroix_StartRedPanel(BoxCroix_StartRedPanel&& _Other) noexcept = delete;
	BoxCroix_StartRedPanel& operator=(const BoxCroix_StartRedPanel& _Other) = delete;
	BoxCroix_StartRedPanel& operator=(BoxCroix_StartRedPanel&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

