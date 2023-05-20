#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class USMissIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	USMissIcon();
	~USMissIcon();

	// delete Function
	USMissIcon(const USMissIcon& _Other) = delete;
	USMissIcon(USMissIcon&& _Other) noexcept = delete;
	USMissIcon& operator=(const USMissIcon& _Other) = delete;
	USMissIcon& operator=(USMissIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> USMissIcons;
	std::shared_ptr<class GameEngineCollision> USMissIconsCollision;
};

