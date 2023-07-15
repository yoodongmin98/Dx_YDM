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

	void LevelStateMoveCheck();
	void BoardMoveCheck();
	void BoardUp();
	//Debug----------------------------------------------
	std::shared_ptr<class GameEngineCollision> GetCollision()
	{
		return BoardsCollision;
	}
	//---------------------------------------------------
	GameEngineTransform* GetBoardRender()
	{
		return Boards->GetTransform();
	}
	void SoudAndText(float _DeltaTime);

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Boards;
	std::shared_ptr<class GameEngineCollision> BoardsCollision;

	bool BoardFunc = true;
	float SoundTime = 0.0f;

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
	std::shared_ptr<class GameEngineFontRenderer> Font6;
};

