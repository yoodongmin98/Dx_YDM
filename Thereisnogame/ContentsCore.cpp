#include "PrecompileHeader.h"
#include "ContentsCore.h"


#include <GameEngineCore\GameEngineCore.h>

//Level
#include "MainMenuLevel.h"


ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::ContentsResourcesCreate()
{

	

}

void ContentsCore::GameStart() 
{
	new int();
	GameEngineCore::CreateLevel<MainMenuLevel>();
	GameEngineCore::ChangeLevel("MainMenuLevel");
}

void ContentsCore::GameEnd() 
{

}