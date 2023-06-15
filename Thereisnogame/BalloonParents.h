#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class BalloonParents : public G_ActorBase
{
public:
	BalloonParents();
	~BalloonParents();

	BalloonParents(const BalloonParents& _Other) = delete;
	BalloonParents(BalloonParents&& _Other) noexcept = delete;
	BalloonParents& operator=(const BalloonParents& _Other) = delete;
	BalloonParents& operator=(BalloonParents&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BalloonParentss;
	std::shared_ptr<class GameEngineCollision> BalloonParentssCollision;
};

