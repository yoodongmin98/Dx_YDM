#include "PrecompileHeader.h"
#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include "GameEngineCamera.h"
#include "GameEngineGUI.h"
#include "GameEngineCollision.h"
#include <GameEnginePlatform/GameEngineInput.h>

GameEngineLevel::GameEngineLevel() 
{
	MainCamera = CreateActor<GameEngineCamera>();

	Cameras.insert(std::make_pair(0, MainCamera));

	std::shared_ptr<GameEngineCamera> UICamera = CreateActor<GameEngineCamera>();
	UICamera->SetProjectionType(CameraType::Orthogonal);

	Cameras.insert(std::make_pair(100, UICamera));

	LastTarget = GameEngineRenderTarget::Create(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, GameEngineWindow::GetScreenSize(), float4::Null);
}

GameEngineLevel::~GameEngineLevel() 
{
}



void GameEngineLevel::Start()
{
}

void GameEngineLevel::ActorUpdate(float _DeltaTime)
{
	if (true == MainCamera->IsFreeCamera())
	{
		MainCamera->Update(_DeltaTime);
		return;
	}

	{
		// �̰� ���߿� ������� �������� ������ �� ������ �Ǵ� ������ �ɰ̴ϴ�.
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupStartIter = Actors.begin();
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupEndIter = Actors.end();

		for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
		{
			std::list<std::shared_ptr<GameEngineActor>>& ActorList = GroupStartIter->second;

			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorStart = ActorList.begin();
			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorEnd = ActorList.end();

			for (; ActorStart != ActorEnd; ++ActorStart)
			{
				std::shared_ptr<GameEngineActor>& Actor = *ActorStart;

				Actor->AllAccTime(_DeltaTime);
				Actor->AllUpdate(_DeltaTime);
			}
		}
	}
}

void GameEngineLevel::ActorLevelChangeStart()
{

	{
		// �̰� ���߿� ������� �������� ������ �� ������ �Ǵ� ������ �ɰ̴ϴ�.
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupStartIter = Actors.begin();
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupEndIter = Actors.end();

		for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
		{
			std::list<std::shared_ptr<GameEngineActor>>& ActorList = GroupStartIter->second;

			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorStart = ActorList.begin();
			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorEnd = ActorList.end();

			for (; ActorStart != ActorEnd; ++ActorStart)
			{
				std::shared_ptr<GameEngineActor>& Actor = *ActorStart;

				Actor->AllLevelChangeStart();
			}
		}
	}
}
void GameEngineLevel::ActorLevelChangeEnd()
{

	{
		// �̰� ���߿� ������� �������� ������ �� ������ �Ǵ� ������ �ɰ̴ϴ�.
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupStartIter = Actors.begin();
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupEndIter = Actors.end();

		for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
		{
			std::list<std::shared_ptr<GameEngineActor>>& ActorList = GroupStartIter->second;

			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorStart = ActorList.begin();
			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorEnd = ActorList.end();

			for (; ActorStart != ActorEnd; ++ActorStart)
			{
				std::shared_ptr<GameEngineActor>& Actor = *ActorStart;

				Actor->AllLevelChangeEnd();
			}
		}
	}
}

void GameEngineLevel::ActorRender(float _DeltaTime)
{
	// GetMainCamera()->Setting();
	// GetMainCamera()->CameraTransformUpdate();
	// GetMainCamera()->Render(_DeltaTime);

	for (std::pair<int, std::shared_ptr<GameEngineCamera>> Pair : Cameras)
	{
		std::shared_ptr<GameEngineCamera> Cam = Pair.second;
		Cam->Setting();
		Cam->CameraTransformUpdate();
		Cam->Render(_DeltaTime);
		Cam->CamTarget->Effect();
	}

	LastTarget->Clear();

	for (std::pair<int, std::shared_ptr<GameEngineCamera>> Pair : Cameras)
	{
		std::shared_ptr<GameEngineCamera> Camera = Pair.second;
		std::shared_ptr<GameEngineRenderTarget> Target = Camera->GetCamTarget();

		LastTarget->Merge(Target);
	}

	// ����۴� ȿ���� �ټ��� �����ϴ�.



	GameEngineDevice::GetBackBufferTarget()->Merge(LastTarget);


	//// �̰� ���߿� ������� �������� ������ �� ������ �Ǵ� ������ �ɰ̴ϴ�.
	//std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupStartIter = Actors.begin();
	//std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupEndIter = Actors.end();

	//for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
	//{
	//	std::list<std::shared_ptr<GameEngineActor>>& ActorList = GroupStartIter->second;

	//	std::list<std::shared_ptr<GameEngineActor>>::iterator ActorStart = ActorList.begin();
	//	std::list<std::shared_ptr<GameEngineActor>>::iterator ActorEnd = ActorList.end();

	//	for (; ActorStart != ActorEnd; ++ActorStart)
	//	{
	//		std::shared_ptr<GameEngineActor>& Actor = *ActorStart;

	//		Actor->AllRender(_DeltaTime);


	//		/*if (false == Actor->IsUpdate())
	//		{
	//			continue;
	//		}

	//		GameEngineTransform* Transform = Actor->GetTransform();
	//		Transform->AllRender(_DeltaTime);*/
	//	}
	//}

	static bool GUIRender = true;

	if (true == GameEngineInput::IsDown("GUISwitch"))
	{
		GUIRender = !GUIRender;
	}

	if (true == GUIRender)
	{
		// GameEngineGUI::Render(GetSharedThis(), _DeltaTime);
	}

}

void GameEngineLevel::ActorRelease()
{
	//// �������� ������ �Ѵ�.
	for (std::pair<int, std::shared_ptr<GameEngineCamera>> Pair : Cameras)
	{
		std::shared_ptr<GameEngineCamera> Cam = Pair.second;
		Cam->Release();
	}

	{
		std::map<int, std::list<std::shared_ptr<GameEngineCollision>>>::iterator GroupStartIter = Collisions.begin();
		std::map<int, std::list<std::shared_ptr<GameEngineCollision>>>::iterator GroupEndIter = Collisions.end();

		for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
		{
			std::list<std::shared_ptr<GameEngineCollision>>& ObjectList = GroupStartIter->second;

			std::list<std::shared_ptr<GameEngineCollision>>::iterator ObjectStart = ObjectList.begin();
			std::list<std::shared_ptr<GameEngineCollision>>::iterator ObjectEnd = ObjectList.end();

			for (; ObjectStart != ObjectEnd; )
			{
				std::shared_ptr<GameEngineCollision> RelaseObject = (*ObjectStart);

				if (nullptr != RelaseObject && false == RelaseObject->IsDeath())
				{
					++ObjectStart;
					continue;
				}

				ObjectStart = ObjectList.erase(ObjectStart);
			}
		}
	}

	
	{
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupStartIter = Actors.begin();
		std::map<int, std::list<std::shared_ptr<GameEngineActor>>>::iterator GroupEndIter = Actors.end();

		for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
		{
			std::list<std::shared_ptr<GameEngineActor>>& ActorList = GroupStartIter->second;

			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorStart = ActorList.begin();
			std::list<std::shared_ptr<GameEngineActor>>::iterator ActorEnd = ActorList.end();

			for (; ActorStart != ActorEnd; )
			{
				std::shared_ptr<GameEngineActor> RelaseActor = (*ActorStart);

				if (nullptr != RelaseActor && false == RelaseActor->IsDeath())
				{
					RelaseActor->AllRelease();
					++ActorStart;
					continue;
				}

				RelaseActor->Release();
				ActorStart = ActorList.erase(ActorStart);
			}
		}
	}

}

void GameEngineLevel::Update(float _DeltaTime) 
{

}

void GameEngineLevel::Render(float _DeltaTime) 
{
}

void GameEngineLevel::ActorInit(std::shared_ptr<GameEngineActor> _Actor, int _Order, GameEngineLevel* _Level)
{
	_Actor->Level = this;
	_Actor->SetOrder(_Order);
	_Actor->Start();

	// Actors[_Order].push_back(_Actor);
}

void GameEngineLevel::PushCollision(std::shared_ptr<GameEngineCollision> _Collision)
{
	Collisions[_Collision->GetOrder()].push_back(_Collision);
}

void GameEngineLevel::LevelChangeStart() 
{

}
void GameEngineLevel::LevelChangeEnd() 
{

}


void GameEngineLevel::PushCameraRenderer(std::shared_ptr<GameEngineRenderer> _Renderer, int _CameraOrder)
{
	std::shared_ptr<GameEngineCamera> FindCamera = GetCamera(_CameraOrder);

	if (nullptr == FindCamera)
	{
		MsgAssert("�������� �ʴ� ī�޶� �������� �������� �����ϴ�.");
		return;
	}

	FindCamera->PushRenderer(_Renderer);
}

std::shared_ptr<GameEngineCamera> GameEngineLevel::GetCamera(int _CameraOrder) 
{
	std::map<int, std::shared_ptr<GameEngineCamera>>::iterator FindIter = Cameras.find(_CameraOrder);

	if (FindIter == Cameras.end())
	{
		return nullptr;
	}

	std::shared_ptr<GameEngineCamera> Camera = FindIter->second;

	return Camera;
}

void GameEngineLevel::TextureUnLoad(GameEngineLevel* _NextLevel)
{
	for (const std::pair<std::string, std::string>& Pair : LoadEndPath)
	{
		if (nullptr != _NextLevel && true == _NextLevel->TexturePath.contains(Pair.first))
		{
			continue;
		}

		GameEngineTexture::UnLoad(Pair.first);
		TexturePath.insert(std::make_pair(Pair.first, Pair.second));
	}

	LoadEndPath.clear();
}

void GameEngineLevel::TextureReLoad(GameEngineLevel* _PrevLevel)
{

	for (const std::pair<std::string, std::string>& Pair : TexturePath)
	{
		if (nullptr != _PrevLevel && true == _PrevLevel->TexturePath.contains(Pair.first))
		{
			continue;
		}

		GameEngineTexture::ReLoad(Pair.second, Pair.first);
		LoadEndPath.insert(std::make_pair(Pair.first, Pair.second));
	}

	TexturePath.clear();
}