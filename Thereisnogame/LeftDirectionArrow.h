#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineLevel.h>
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
	void CameraMoveCheck(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDirectionArrows;
	std::shared_ptr<class GameEngineCollision> LeftDirectionArrowsCollision;

	GameEngineTransform* Cameras = nullptr;

	float4 StartCameraPos = float4::Zero;
	float4 EndCameraPos = float4::Zero;

	bool LeftCameraMoveBool = true;
	float MoveTime = 0.0f;
};

