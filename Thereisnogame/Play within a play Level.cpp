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
#include "Vis.h"

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
	//����� �����Ҷ� ���������� ������
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

		
		CreateActor<Cordon>();
	}
	{
		CreateActor<Mouse>();
	}
}

void PlaywithinaplayLevel::Update(float _DeltaTime)
{

}