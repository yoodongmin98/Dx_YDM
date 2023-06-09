#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_CodePicture : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_CodePicture();
	~BoxCroix_CodePicture();

	// delete Function
	BoxCroix_CodePicture(const BoxCroix_CodePicture& _Other) = delete;
	BoxCroix_CodePicture(BoxCroix_CodePicture&& _Other) noexcept = delete;
	BoxCroix_CodePicture& operator=(const BoxCroix_CodePicture& _Other) = delete;
	BoxCroix_CodePicture& operator=(BoxCroix_CodePicture&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

