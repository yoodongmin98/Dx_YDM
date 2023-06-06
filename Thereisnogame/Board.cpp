#include "PrecompileHeader.h"
#include "Board.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "Play within a play Level.h"
#include "LevelStateManager.h"
#include "Play within a play Level.h"
Board::Board()
{
}

Board::~Board()
{
}

void Board::Start()
{
	Boards = Init(Boards, "Board.png", { 776,422 }, { 0,70,0 });
	BoardsCollision = CollisionInit(BoardsCollision, { 770,420 }, { 0,70,0 });
}

void Board::Update(float _DeltaTime)
{
	Repeat(4, _DeltaTime*0.5f);
	BoardMoveCheck();
	if (false == LevelStateManager::MG->GetIsProgress()
		&& true == ClickCheck(BoardsCollision))
	{
		BoardsCollision->Death();
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::DownBoard);
	}
}

void Board::Render(float _Delta)
{

};
bool Boardmoves = true;
void Board::BoardMoveCheck()
{
	if (Chap1LevelState::DownBoard == PlaywithinaplayLevel::LM->GetLevelState()
		&& true==Boardmoves)
	{
		GetTransform()->AddLocalPosition({ 0,-1,0 });
		if (GetTransform()->GetLocalPosition().y < -70.0f)
		{
			LevelStateManager::MG->SetIsBoardDownTrue();
			Boardmoves = false;
		}
	}
}

//Functional È£Ãâ¿ë
void Board::BoardUp()
{
	Boardmoves = true;
	GetTransform()->AddLocalPosition({ 0,1,0 });
	if (GetTransform()->GetLocalPosition().y > 70.0f)
	{
		Boardmoves = false;//
	}
}
void Board::BoardDown()
{

}

