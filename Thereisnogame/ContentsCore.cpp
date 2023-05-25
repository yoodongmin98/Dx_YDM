#include "PrecompileHeader.h"
#include "ContentsCore.h"


#include <GameEngineCore\GameEngineCore.h>

//Level
#include "MainMenuLevel.h"
#include "Program Loading Level.h"
#include "Play within a play Level.h"
#include "Fake Program Level.h"

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
	GameEngineCore::CreateLevel<PlaywithinaplayLevel>();
	GameEngineCore::CreateLevel<ProgramLoadingLevel>();
	GameEngineCore::CreateLevel<FakeProgramLevel>();

	GameEngineCore::ChangeLevel("MainMenuLevel");
}

void ContentsCore::GameEnd() 
{

}