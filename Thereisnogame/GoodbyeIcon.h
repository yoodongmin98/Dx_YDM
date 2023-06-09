#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class GoodbyeIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	GoodbyeIcon();
	~GoodbyeIcon();

	// delete Function
	GoodbyeIcon(const GoodbyeIcon& _Other) = delete;
	GoodbyeIcon(GoodbyeIcon&& _Other) noexcept = delete;
	GoodbyeIcon& operator=(const GoodbyeIcon& _Other) = delete;
	GoodbyeIcon& operator=(GoodbyeIcon&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> GoodbyeIcons;
	std::shared_ptr<class GameEngineCollision> GoodbyeIconsCollision;

	std::shared_ptr<class FolderNote_GoodBye> FolderNote_GoodByePtr;
	std::shared_ptr<class BoxCroix_FN1> BoxCroix_FN1Ptr;
};

