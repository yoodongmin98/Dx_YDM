#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_ClockPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_ClockPanel();
	~BoxCroix_ClockPanel();

	// delete Function
	BoxCroix_ClockPanel(const BoxCroix_ClockPanel& _Other) = delete;
	BoxCroix_ClockPanel(BoxCroix_ClockPanel&& _Other) noexcept = delete;
	BoxCroix_ClockPanel& operator=(const BoxCroix_ClockPanel& _Other) = delete;
	BoxCroix_ClockPanel& operator=(BoxCroix_ClockPanel&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

