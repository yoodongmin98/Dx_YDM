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

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FRMissIcons;
	std::shared_ptr<class GameEngineCollision> FRMissIconsCollision;

	std::shared_ptr<class MissPicture> MissPicturePtr;
	std::shared_ptr<class BoxCroix_PR_MissPicture> BoxCroix_PR_MissPicturePtr;
	std::shared_ptr<class LeftRotate> LeftRotatePtr;
	std::shared_ptr<class RightRotate> RightRotatePtr;
};

