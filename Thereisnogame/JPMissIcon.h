#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class JPMissIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	JPMissIcon();
	~JPMissIcon();

	// delete Function
	JPMissIcon(const JPMissIcon& _Other) = delete;
	JPMissIcon(JPMissIcon&& _Other) noexcept = delete;
	JPMissIcon& operator=(const JPMissIcon& _Other) = delete;
	JPMissIcon& operator=(JPMissIcon&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> JPMissIcons;
	std::shared_ptr<class GameEngineCollision> JPMissIconsCollision;

	std::shared_ptr<class MissPicture> MissPicturePtr;
	std::shared_ptr<class BoxCroix_PR_MissPicture> BoxCroix_PR_MissPicturePtr;
	std::shared_ptr<class LeftRotate> LeftRotatePtr;
	std::shared_ptr<class RightRotate> RightRotatePtr;
};

