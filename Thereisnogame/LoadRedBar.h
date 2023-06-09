#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class LoadRedBar : public G_ActorBase
{
public:
	LoadRedBar();
	~LoadRedBar();

	LoadRedBar(const LoadRedBar& _Other) = delete;
	LoadRedBar(LoadRedBar&& _Other) noexcept = delete;
	LoadRedBar& operator=(const LoadRedBar& _Other) = delete;
	LoadRedBar& operator=(LoadRedBar&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LoadRedBars;
	std::shared_ptr<class GameEngineCollision> LoadRedBarsCollision;
};

