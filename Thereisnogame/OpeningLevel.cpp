#include "PrecompileHeader.h"
#include "OpeningLevel.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>


//Actor
#include "Mouse.h"
#include "FadeEffect.h"
#include "BlueErrorMessage.h"


OpeningLevel::OpeningLevel()
{

}

OpeningLevel::~OpeningLevel()
{
}



void OpeningLevel::Start()
{
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter -1(Opening)");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}

	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });
	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();
	
	BlueErrorMessagePtr=CreateActor<BlueErrorMessage>();
}

void OpeningLevel::Update(float _DeltaTime)
{
	if (BlueErrorMessagePtr.get()->GetLiveTime() > 4.0f)
	{
		GameEngineCore::ChangeLevel("MainMenuLevel");
	}
}

void OpeningLevel::LevelChangeStart()
{
	FEffect->FadeOut();
}