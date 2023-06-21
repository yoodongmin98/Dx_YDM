#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class AlphaCircle :public G_ActorBase
{
public:
	AlphaCircle();
	~AlphaCircle();

	AlphaCircle(const AlphaCircle& _Other) = delete;
	AlphaCircle(AlphaCircle&& _Other)noexcept = delete;
	AlphaCircle operator=(AlphaCircle&& _Other) = delete;
	AlphaCircle operator=(const AlphaCircle& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> AlphaCircles;

	float LocalX = 0.0;
};

