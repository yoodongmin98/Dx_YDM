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
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("Shader");
	NewDir.Move("Shader");

	std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".hlsl", ".fx" });

	for (size_t i = 0; i < Files.size(); i++)
	{
		GameEngineShader::AutoCompile(Files[i]);
	}
	
}

void ContentsCore::GameStart() 
{
	ContentsResourcesCreate();
	ResourceInit("FadeShader.hlsl", "Fade");
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