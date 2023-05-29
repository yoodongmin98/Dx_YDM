#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>



//Actor
#include "C1_BackGround.h"
#include "Mouse.h"
#include "AlphaCircle.h"
#include "BackGround_White.h"

PlaywithinaplayLevel::PlaywithinaplayLevel()
{
}

PlaywithinaplayLevel::~PlaywithinaplayLevel()
{
}



void PlaywithinaplayLevel::Start()
{
	//ImageLoad
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ThereisnogameResource");
		NewDir.Move("ThereisnogameResource");
		NewDir.Move("Chapter1(Start)");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}



	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	{
		CreateActor<C1_BackGround>();
		CreateActor<Mouse>();
		CreateActor<AlphaCircle>();
	}

}

void PlaywithinaplayLevel::Update(float _DeltaTime)
{

}