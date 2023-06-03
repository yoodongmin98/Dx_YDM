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
#include "Plaque.h"
#include "BackCurtain.h"
#include "Cordon.h"
#include "Vis.h"
#include "FadeEffect.h"
//ScreenActor
#include "Cog.h"

PlaywithinaplayLevel* PlaywithinaplayLevel::LM;
PlaywithinaplayLevel::PlaywithinaplayLevel()
{
	LM = this;
}

PlaywithinaplayLevel::~PlaywithinaplayLevel()
{
}



void PlaywithinaplayLevel::Start()
{
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
	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();
	//여기는 시작할때 만들어놓을게 많을듯
	{
		CreateActor<C1_BackGround>();
		CreateActor<Plaque>();
		Vis1 = CreateActor<Vis>();
		Vis1->SetVisPosition({ -180,130 });
		Vis1->SetVisRotate({ 0,0,45 });

		Vis2 = CreateActor<Vis>();
		Vis2->SetVisPosition({ -180,-25 });
		Vis2->SetVisRotate({ 0,0,135 });

		Vis3 = CreateActor<Vis>();
		Vis3->SetVisPosition({ 180,130 });
		Vis3->SetVisRotate({ 0,0,-45 });

		Vis4 = CreateActor<Vis>();
		Vis4->SetVisPosition({ 180,-25 });
		Vis4->SetVisRotate({ 0,0,-135 });

		BackCurtainPtr=CreateActor<BackCurtain>();
		CreateActor<Cordon>();
	}
	{
		//Test용 ScreenActor
		//CreateActor<Cog>();
		MousePtr=CreateActor<Mouse>();
	}

	ChangeState(Chap1LevelState::None);
}

void PlaywithinaplayLevel::Update(float _DeltaTime)
{
	//임시용
	if (GameEngineInput::IsDown("TestKey1"))
	{
		GameEngineCore::ChangeLevel("MainMenuLevel");
	}
	if (GameEngineInput::IsDown("TestKey3"))
	{
		GameEngineCore::ChangeLevel("FakeProgramLevel");
	}
	UpdateState(_DeltaTime);
}

void PlaywithinaplayLevel::LevelChangeStart()
{
	FEffect->FadeOut();
}