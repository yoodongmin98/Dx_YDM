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
	if (Chap1LevelState::SlantBoard > PlaywithinaplayLevel::LM->GetLevelState())
	{
		Repeat(5, _DeltaTime*0.7f);
	}
	BoardMoveCheck();
	LevelStateMoveCheck();
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
	if (false == LevelStateManager::MG->GetIsProgress()
		&& true == ClickCheck(BoardsCollision))
	{
		BoardsCollision->Death();
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::DownBoard);
	}
}


bool RemoveDown = true;
void Board::LevelStateMoveCheck()
{
	if (Chap1LevelState::SlantBoard == PlaywithinaplayLevel::LM->GetLevelState()
		&&true== RemoveDown)
	{
		GetTransform()->AddLocalPosition({ 0,-2.0f,0 });
		GetTransform()->AddLocalRotation({ 0,0,-0.03f });
		if (GetTransform()->GetLocalPosition().y < -60.0f)
		{
			RemoveDown = false;
			LevelStateManager::MG->SetIsSlantBoardTrue();
		}
	}
}


//Functional È£Ãâ¿ë
void Board::BoardUp()
{
	if (true == BoardFunc)
	{
		GetTransform()->AddLocalPosition({ 0,1,0 });
	}
	if (GetTransform()->GetLocalPosition().y > 70.0f)
	{
		BoardFunc = false;
	}
}
void Board::BoardDown()
{

}

