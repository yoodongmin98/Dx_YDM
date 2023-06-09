#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_PictureFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_PictureFolder();
	~BoxCroix_PictureFolder();

	// delete Function
	BoxCroix_PictureFolder(const BoxCroix_PictureFolder& _Other) = delete;
	BoxCroix_PictureFolder(BoxCroix_PictureFolder&& _Other) noexcept = delete;
	BoxCroix_PictureFolder& operator=(const BoxCroix_PictureFolder& _Other) = delete;
	BoxCroix_PictureFolder& operator=(BoxCroix_PictureFolder&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

