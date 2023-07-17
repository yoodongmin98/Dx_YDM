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
	void BlinkArrow(float _DeltaTime);
	void CameraMoveCheck(float _DeltaTime);

	void SoundAndText(float _DeltaTime);
protected:
	GameEngineSoundPlayer Sound;
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

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
	std::shared_ptr<class GameEngineFontRenderer> Font6;
	std::shared_ptr<class GameEngineFontRenderer> Font7;
	std::shared_ptr<class GameEngineFontRenderer> Font8;
	std::shared_ptr<class GameEngineFontRenderer> Font9;
	std::shared_ptr<class GameEngineFontRenderer> Font10;
	std::shared_ptr<class GameEngineFontRenderer> Font11;
	std::shared_ptr<class GameEngineFontRenderer> Font12;
	std::shared_ptr<class GameEngineFontRenderer> Font13;
	std::shared_ptr<class GameEngineFontRenderer> Font14;
	std::shared_ptr<class GameEngineFontRenderer> Font15;
	std::shared_ptr<class GameEngineFontRenderer> Font16;
	std::shared_ptr<class GameEngineFontRenderer> Font17;
	std::shared_ptr<class GameEngineFontRenderer> Font18;
	std::shared_ptr<class GameEngineFontRenderer> Font19;
	std::shared_ptr<class GameEngineFontRenderer> Font20;

	float SoundTime = 0.0f;
};

