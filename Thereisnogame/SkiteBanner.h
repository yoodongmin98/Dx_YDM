#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SkiteBanner : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteBanner();
	~SkiteBanner();

	// delete Function
	SkiteBanner(const SkiteBanner& _Other) = delete;
	SkiteBanner(SkiteBanner&& _Other) noexcept = delete;
	SkiteBanner& operator=(const SkiteBanner& _Other) = delete;
	SkiteBanner& operator=(SkiteBanner&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteBanners;
};

