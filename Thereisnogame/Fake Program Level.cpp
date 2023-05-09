#include "PrecompileHeader.h"
#include "Fake Program Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>


//Actor
#include "AlphaCircle.h"
#include "C2_BackGround.h"
#include "squirrel.h"

//Folder
#include "SkiteFolder.h"
#include "ZipWipFolder.h"


FakeProgramLevel::FakeProgramLevel()
{
}

FakeProgramLevel::~FakeProgramLevel()
{
}



void FakeProgramLevel::Start()
{
	//ImageLoad
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter2(window)");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	//백그라운드부터 순서대로(나중에 렌더될수록 가장 앞으로나옴)
	{
		CreateActor<C2_BackGround>();
		CreateActor<squirrel>();
		FolderCreate();
		CreateActor<AlphaCircle>();
	}

}

void FakeProgramLevel::Update(float _DeltaTime)
{
	
}

void FakeProgramLevel::FolderCreate()
{
	CreateActor<SkiteFolder>();
	CreateActor<ZipWipFolder>();
}