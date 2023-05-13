#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class FRMissIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	FRMissIcon();
	~FRMissIcon();

	// delete Function
	FRMissIcon(const FRMissIcon& _Other) = delete;
	FRMissIcon(FRMissIcon&& _Other) noexcept = delete;
	FRMissIcon& operator=(const FRMissIcon& _Other) = delete;
	FRMissIcon& operator=(FRMissIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FRMissIcons;
};

