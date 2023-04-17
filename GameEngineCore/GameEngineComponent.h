#pragma once
#include "GameEngineActor.h"

// ���� :
class GameEngineComponent : public GameEngineUpdateObject
{
	friend class GameEngineActor;

public:
	// constrcuter destructer
	GameEngineComponent();
	~GameEngineComponent();

	// delete Function
	GameEngineComponent(const GameEngineComponent& _Other) = delete;
	GameEngineComponent(GameEngineComponent&& _Other) noexcept = delete;
	GameEngineComponent& operator=(const GameEngineComponent& _Other) = delete;
	GameEngineComponent& operator=(GameEngineComponent&& _Other) noexcept = delete;

	class GameEngineActor* GetActor() 
	{
		return Actor;
	}

	class GameEngineLevel* GetLevel()
	{
		return Actor->GetLevel();
	}

protected:

private:
	class GameEngineActor* Actor;

	void SetActor(class GameEngineActor* _Actor);

};

