#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

class Cursor : public S_ActorBase
{
public:
	Cursor();
	~Cursor();

	Cursor(const Cursor& _Other) = delete;
	Cursor(Cursor&& _Other) noexcept = delete;
	Cursor& operator=(const Cursor& _Other) = delete;
	Cursor& operator=(Cursor&& _Other) noexcept = delete;

	void CollisionDeathCheck();
	void CursorMoveCheck(float _DeltaTime);
	void SoundAndText(float _DeltaTime);
protected:
	GameEngineSoundPlayer Sound;
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cursors;
	std::shared_ptr<class GameEngineSpriteRenderer> Cursor_Overlap;
	std::shared_ptr<class GameEngineCollision> CursorsCollision;

	float4 Starts = float4::Zero;
	float4 Ends = float4::Zero;

	float4 StartPosition = float4::Zero;
	float4 Positions = float4::Zero;
	float MoveTime = 0.0f;
	float SoundTime = 0.0f;
	float TextTime = 0.0f;

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
};

