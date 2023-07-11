#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_TrashCanFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_TrashCanFolder();
	~BoxCroix_TrashCanFolder();

	// delete Function
	BoxCroix_TrashCanFolder(const BoxCroix_TrashCanFolder& _Other) = delete;
	BoxCroix_TrashCanFolder(BoxCroix_TrashCanFolder&& _Other) noexcept = delete;
	BoxCroix_TrashCanFolder& operator=(const BoxCroix_TrashCanFolder& _Other) = delete;
	BoxCroix_TrashCanFolder& operator=(BoxCroix_TrashCanFolder&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

