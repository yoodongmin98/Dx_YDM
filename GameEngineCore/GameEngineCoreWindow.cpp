#include "PrecompileHeader.h"
#include "GameEngineCoreWindow.h"

GameEngineCoreWindow::GameEngineCoreWindow() 
{
}

GameEngineCoreWindow::~GameEngineCoreWindow() 
{
}


void GameEngineCoreWindow::OnGUI(std::shared_ptr<GameEngineLevel> Level, float _DeltaTime)
{
	if (ImGui::Button("fasdhjkfsadhjkfasd"))
	{
		if (nullptr != Test)
		{
			Test();
		}
	}

}