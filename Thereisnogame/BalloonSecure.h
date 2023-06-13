#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class BalloonSecure : public G_ActorBase
{
public:
	BalloonSecure();
	~BalloonSecure();

	BalloonSecure(const BalloonSecure& _Other) = delete;
	BalloonSecure(BalloonSecure&& _Other) noexcept = delete;
	BalloonSecure& operator=(const BalloonSecure& _Other) = delete;
	BalloonSecure& operator=(BalloonSecure&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BalloonSecures;
	std::shared_ptr<class GameEngineCollision> BalloonSecuresCollision;
};

