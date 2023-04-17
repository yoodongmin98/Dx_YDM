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

	//// �̰� ������Ʈ ������� �մϴ�.
	std::list<std::shared_ptr<class GameEngineComponent>> ComponentsList;

	void ComponentInit(std::shared_ptr<class GameEngineComponent> _Component);

	void ComponentsUpdate(float _DeltaTime);

	void ComponentsRender(float _DeltaTime);

};

