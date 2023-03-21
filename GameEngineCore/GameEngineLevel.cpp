#include "GameEngineLevel.h"
#include "GameEngineActor.h"

GameEngineLevel::GameEngineLevel()
{
}

GameEngineLevel::~GameEngineLevel()
{
}



void GameEngineLevel::Loading()
{


}

void GameEngineLevel::Update(float _DeltaTime)
{
	for (std::pair<int, std::list<std::shared_ptr<GameEngineActor>>> OrderGroup : Actors)
	{
		std::list<std::shared_ptr<GameEngineActor>>& ActorList = OrderGroup.second;

		// TimeScale;
		// ���Ŀ� �����ϰڴ�.
		for (std::shared_ptr<GameEngineActor> Actor : ActorList)
		{
			Actor->Update(_DeltaTime);
		}
	}
}

void GameEngineLevel::Render(float _DeltaTime)
{
	// �̰� ���߿� ������� �������� ������ �� ������ �Ǵ� ������ �ɰ̴ϴ�.
	for (std::pair<int, std::list<std::shared_ptr<GameEngineActor>>> OrderGroup : Actors)
	{
		std::list<std::shared_ptr<GameEngineActor>>& ActorList = OrderGroup.second;

		// TimeScale;
		// ���Ŀ� �����ϰڴ�.
		for (std::shared_ptr<GameEngineActor> Actor : ActorList)
		{
			Actor->Render(_DeltaTime);
		}
	}
}

void GameEngineLevel::ActorInit(std::shared_ptr<GameEngineActor> _Actor, int _Order, GameEngineLevel* _Parent)
{
	_Actor->SetParent(_Parent);
	_Actor->SetOrder(_Order);
	_Actor->Start();
}