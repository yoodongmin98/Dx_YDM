#include "PrecompileHeader.h"
#include "GameCore.h"
#include <GameEngineCore\GameEngineCore.h>

#include "MenuLevel.h"

GameCore::GameCore()
{
}

GameCore::~GameCore()
{
}

void GameCore::GameStart()
{
	//Leak Check¿ë
	new int();
	GameEngineCore::CreateLevel<MenuLevel>();
	GameEngineCore::ChangeLevel("MenuLevel");
	//GameEngineCore::CreateLevel<PlayLevel>();
	//GameEngineCore::ChangeLevel("PlayLevel");
}

void GameCore::GameEnd()
{

}