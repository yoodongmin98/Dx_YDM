#include "PrecompileHeader.h"
#include "Program Loading Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>



//Actor
#include "Ball_TitleCube.h"
ProgramLoadingLevel::ProgramLoadingLevel()
{
}

ProgramLoadingLevel::~ProgramLoadingLevel()
{
}



void ProgramLoadingLevel::Start()
{
	//ImageLoad
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter1.5(Loading)");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	//��׶������ �������(���߿� �����ɼ��� ���� �����γ���)
	{
		CreateActor<Ball_TitleCube>();
	}

}

void ProgramLoadingLevel::Update(float _DeltaTime)
{
	
}