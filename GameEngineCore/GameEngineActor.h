#pragma once
#include "GameEngineUpdateObject.h"

// ���� :
class GameEngineActor : public GameEngineUpdateObject
{
	friend class GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineActor();
	~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline class GameEngineLevel* GetLevel() const
	{
		return Level;
	}

	template<typename ComponentType>
	std::shared_ptr<ComponentType> CreateComponent()
	{
		std::shared_ptr<class GameEngineComponent> NewComponent = std::make_shared<ComponentType>();

		ComponentInit(NewComponent);

		return std::dynamic_pointer_cast<ComponentType>(NewComponent);
	}

protected:
	virtual void Start() {}
	virtual void Update(float _DeltaTime) {}
	virtual void Render(float _DeltaTime) {}

private:
	class GameEngineLevel* Level = nullptr;

	void ComponentInit(std::shared_ptr<class GameEngineComponent> _Component);

	
};

