#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SkiteFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteFolder();
	~SkiteFolder();

	// delete Function
	SkiteFolder(const SkiteFolder& _Other) = delete;
	SkiteFolder(SkiteFolder&& _Other) noexcept = delete;
	SkiteFolder& operator=(const SkiteFolder& _Other) = delete;
	SkiteFolder& operator=(SkiteFolder&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteFolders;
	std::shared_ptr<class GameEngineCollision> SkiteFoldersCollision;

	std::shared_ptr<class Skite> SkitePtr;
	std::shared_ptr<class SkiteBanner> SkiteBannerPtr;
	std::shared_ptr<class BoxCroix_Skite> BoxCroix_SkitePtr;
	std::shared_ptr<class SkiteIcon> SkiteIconPtr;
};

