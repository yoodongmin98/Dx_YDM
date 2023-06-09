#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_DayPicture : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_DayPicture();
	~BoxCroix_DayPicture();

	// delete Function
	BoxCroix_DayPicture(const BoxCroix_DayPicture& _Other) = delete;
	BoxCroix_DayPicture(BoxCroix_DayPicture&& _Other) noexcept = delete;
	BoxCroix_DayPicture& operator=(const BoxCroix_DayPicture& _Other) = delete;
	BoxCroix_DayPicture& operator=(BoxCroix_DayPicture&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

