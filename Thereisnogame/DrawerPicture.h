#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class DrawerPicture : public G_ActorBase
{
public:
	// constrcuter destructer
	DrawerPicture();
	~DrawerPicture();

	// delete Function
	DrawerPicture(const DrawerPicture& _Other) = delete;
	DrawerPicture(DrawerPicture&& _Other) noexcept = delete;
	DrawerPicture& operator=(const DrawerPicture& _Other) = delete;
	DrawerPicture& operator=(DrawerPicture&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> DrawerOpen;
	std::shared_ptr<class GameEngineSpriteRenderer> DrawerClose;

	std::shared_ptr<class GameEngineCollision> DrawerCollision;
};

