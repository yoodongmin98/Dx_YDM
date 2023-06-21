#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class LeftDirectionArrow : public G_ActorBase
{
public:
	LeftDirectionArrow();
	~LeftDirectionArrow();

	LeftDirectionArrow(const LeftDirectionArrow& _Other) = delete;
	LeftDirectionArrow(LeftDirectionArrow&& _Other) noexcept = delete;
	LeftDirectionArrow& operator=(const LeftDirectionArrow& _Other) = delete;
	LeftDirectionArrow& operator=(LeftDirectionArrow&& _Other) noexcept = delete;
	void BlinkArrow();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDirectionArrows;
	std::shared_ptr<class GameEngineCollision> LeftDirectionArrowsCollision;
};

