#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Board : public G_ActorBase
{
public:
	Board();
	~Board();

	Board(const Board& _Other) = delete;
	Board(Board&& _Other) noexcept = delete;
	Board& operator=(const Board& _Other) = delete;
	Board& operator=(Board&& _Other) noexcept = delete;

	void BoardMoveCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Boards;
	std::shared_ptr<class GameEngineCollision> BoardsCollision;
};

