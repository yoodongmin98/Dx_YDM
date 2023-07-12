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

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> USMissIcons;
	std::shared_ptr<class GameEngineCollision> USMissIconsCollision;
	
	std::shared_ptr<class MissPicture> MissPicturePtr;
	std::shared_ptr<class BoxCroix_PR_MissPicture> BoxCroix_PR_MissPicturePtr;
	std::shared_ptr<class LeftRotate> LeftRotatePtr;
	std::shared_ptr<class RightRotate> RightRotatePtr;

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
};

