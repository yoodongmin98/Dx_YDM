#include "PrecompileHeader.h"
#include "Program Loading Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>



//Actor
#include "LoadBarTXT.h"
#include "Mouse.h"
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
		CreateActor<LoadBarTXT>();
		CreateActor<Mouse>();
	}

}

void ProgramLoadingLevel::Update(float _DeltaTime)
{
	
}