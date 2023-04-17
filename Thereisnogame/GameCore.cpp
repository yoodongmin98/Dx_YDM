#include "PrecompileHeader.h"
#include "GameCore.h"
#include <GameEngineCore\GameEngineCore.h>

#include "PlayLevel.h"
#include "TitleLevel.h"
GameCore::GameCore()
{
}

GameCore::~GameCore()
{
}

void GameCore::GameStart()
{
	new int();
	GameEngineCore::CreateLevel<TitleLevel>();
	GameEngineCore::CreateLevel<PlayLevel>();
	GameEngineCore::ChangeLevel("PlayLevel");
}

void GameCore::GameEnd()
{

}