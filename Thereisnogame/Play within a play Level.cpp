#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCamera.h>


//Actor
#include "C1_BackGround.h"
#include "Mouse.h"
#include "AlphaCircle.h"
#include "BackGround_White.h"
#include "Plaque.h"
#include "BackCurtain.h"
#include "Cordon.h"

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
	//여기는 시작할때 만들어놓을게 많을듯
	{
		CreateActor<C1_BackGround>();
		CreateActor<Plaque>();
		CreateActor<Cordon>();
		
	}
	{
		CreateActor<Mouse>();
	}
}

void PlaywithinaplayLevel::Update(float _DeltaTime)
{

}