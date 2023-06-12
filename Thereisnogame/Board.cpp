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
	BoardMoveCheck();
	LevelStateMoveCheck();
}

void Board::Render(float _Delta)
{

};


bool Boardmoves = true;
void Board::BoardMoveCheck()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (Chap1LevelState::DownBoard == PlaywithinaplayLevel::LM->GetLevelState()
		&& true==Boardmoves)
	{
		GetTransform()->AddLocalPosition({ 0,-1*Times,0 });
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
	float Times=GameEngineTime::GlobalTime.GetDeltaTime()*200;
	if (Chap1LevelState::SlantBoard == PlaywithinaplayLevel::LM->GetLevelState()
		&&true== RemoveDown)
	{
		LevelStateManager::MG->SetLopeDownStartTrue();
		GetTransform()->AddLocalPosition({ 0,-1.0f*Times,0 });
		GetTransform()->AddLocalRotation({ 0,0,-0.04f*Times });
		if (GetTransform()->GetLocalPosition().y < -80.0f)
		{
			RemoveDown = false;
			LevelStateManager::MG->SetIsSlantBoardTrue();
			LevelStateManager::MG->SetLopeDownStartFalse();
		}
	}
}


//Functional È£Ãâ¿ë
void Board::BoardUp()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (true == BoardFunc)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
	}
	if (GetTransform()->GetLocalPosition().y > 70.0f)
	{
		BoardFunc = false;
	}
}

