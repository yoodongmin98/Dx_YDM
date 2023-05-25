#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SkiteIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteIcon();
	~SkiteIcon();

	// delete Function
	SkiteIcon(const SkiteIcon& _Other) = delete;
	SkiteIcon(SkiteIcon&& _Other) noexcept = delete;
	SkiteIcon& operator=(const SkiteIcon& _Other) = delete;
	SkiteIcon& operator=(SkiteIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteIcons;
	std::shared_ptr<class GameEngineCollision> SkiteIconsCollision;

	std::shared_ptr<class SkiteProfil> SkiteProfilPtr;

};

