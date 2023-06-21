#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class RightDirectionArrow : public G_ActorBase
{
public:
	RightDirectionArrow();
	~RightDirectionArrow();

	RightDirectionArrow(const RightDirectionArrow& _Other) = delete;
	RightDirectionArrow(RightDirectionArrow&& _Other) noexcept = delete;
	RightDirectionArrow& operator=(const RightDirectionArrow& _Other) = delete;
	RightDirectionArrow& operator=(RightDirectionArrow&& _Other) noexcept = delete;
	void BlinkArrow();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> RightDirectionArrows;
	std::shared_ptr<class GameEngineCollision> RightDirectionArrowsCollision;
};

