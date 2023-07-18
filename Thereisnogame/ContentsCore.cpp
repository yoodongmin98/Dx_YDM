#include "PrecompileHeader.h"
#include "ContentsCore.h"


#include <GameEngineCore\GameEngineCore.h>

//Level
#include "MainMenuLevel.h"
#include "Program Loading Level.h"
#include "Play within a play Level.h"
#include "Fake Program Level.h"
#include "OpeningLevel.h"
#include "EndingLevel.h"

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
	ResourceInit("FadeShader.hlsl", "Fade");
	ResourceInit("DebugMeshRender.hlsl", "Meshs");
}

void ContentsCore::GameStart() 
{
	ContentsResourcesCreate();
	
	new int(); //LeakCheck¿ë
	GameEngineCore::CreateLevel<OpeningLevel>();
	GameEngineCore::CreateLevel<MainMenuLevel>();
	GameEngineCore::CreateLevel<PlaywithinaplayLevel>();
	GameEngineCore::CreateLevel<ProgramLoadingLevel>();
	GameEngineCore::CreateLevel<FakeProgramLevel>();
	GameEngineCore::CreateLevel<EndingLevel>();

	GameEngineCore::ChangeLevel("MainMenuLevel");
}

void ContentsCore::GameEnd() 
{

}