#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix_DrawerPicture : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix_DrawerPicture();
	~BoxCroix_DrawerPicture();

	// delete Function
	BoxCroix_DrawerPicture(const BoxCroix_DrawerPicture& _Other) = delete;
	BoxCroix_DrawerPicture(BoxCroix_DrawerPicture&& _Other) noexcept = delete;
	BoxCroix_DrawerPicture& operator=(const BoxCroix_DrawerPicture& _Other) = delete;
	BoxCroix_DrawerPicture& operator=(BoxCroix_DrawerPicture&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;
};

