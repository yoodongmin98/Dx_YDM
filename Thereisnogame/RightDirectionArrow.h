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
	void CameraMoveCheck(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> RightDirectionArrows;
	std::shared_ptr<class GameEngineCollision> RightDirectionArrowsCollision;

	GameEngineTransform* Cameras = nullptr;

	float4 StartCameraPos = float4::Zero;
	float4 EndCameraPos = float4::Zero;

	bool RightCameraMoveBool = true;
	float MoveTime = 0.0f;
};

