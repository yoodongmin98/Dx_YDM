#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class LoadBarTXT : public G_ActorBase
{
public:
	LoadBarTXT();
	~LoadBarTXT();

	LoadBarTXT(const LoadBarTXT& _Other) = delete;
	LoadBarTXT(LoadBarTXT&& _Other) noexcept = delete;
	LoadBarTXT& operator=(const LoadBarTXT& _Other) = delete;
	LoadBarTXT& operator=(LoadBarTXT&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LoadBarTXTs;
	std::shared_ptr<class GameEngineCollision> LoadBarTXTsCollision;

	float TestTime = 0.0f;
};

