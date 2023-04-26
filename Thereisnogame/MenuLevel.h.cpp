#include "PrecompileHeader.h"

#include "MenuLevel.h"
//Base
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
//PlatForm
 
//Core
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCamera.h>



MenuLevel::MenuLevel()
{

}

MenuLevel::~MenuLevel()
{
}




void MenuLevel::Start()
{
	{
		GameEngineDirectory MenuDir;
		MenuDir.MoveParentToDirectory("ThereisnogameResource");
		MenuDir.Move("ThereisnogameResource");
		MenuDir.Move("Chapter0(MainMenu)");

		std::vector<GameEngineFile> File = MenuDir.GetAllFile({ ".Png", });


		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
		
	}
	GetMainCamera()->SetProjectionType(CameraType::Perspective);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });
}


void MenuLevel::Update(float _DeltaTime)
{

}