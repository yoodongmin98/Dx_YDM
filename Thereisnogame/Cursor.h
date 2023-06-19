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
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cursors;
	std::shared_ptr<class GameEngineSpriteRenderer> Cursor_Overlap;
	std::shared_ptr<class GameEngineCollision> CursorsCollision;

	float4 Starts = float4::Zero;
	float4 Ends = float4::Zero;

	float4 Positions = float4::Zero;
	float MoveTime = 0.0f;
};

