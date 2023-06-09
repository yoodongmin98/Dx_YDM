#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Plaque : public G_ActorBase
{
public:
	Plaque();
	~Plaque();

	Plaque(const Plaque& _Other) = delete;
	Plaque(Plaque&& _Other) noexcept = delete;
	Plaque& operator=(const Plaque& _Other) = delete;
	Plaque& operator=(Plaque&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Plaques;
	std::shared_ptr<class GameEngineCollision> PlaquesCollision;

	int ClickCount = 0;
};

