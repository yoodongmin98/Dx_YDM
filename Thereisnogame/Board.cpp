#include "PrecompileHeader.h"
#include "Board.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "Play within a play Level.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::Start()
{
	Boards = Init(Boards, "Board.png", { 776,422 }, { 0,0,0 });
}

void Board::Update(float _DeltaTime)
{
	Repeat(5, _DeltaTime);
}

void Board::Render(float _Delta)
{

};


