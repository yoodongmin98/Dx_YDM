#pragma once
#include <GameEngineCore/GameEngineActor.h>


class ColManager : public GameEngineActor
{
public:
	static ColManager* MG;
	// constrcuter destructer
	ColManager();
	~ColManager();

	// delete Function
	ColManager(const ColManager& _Other) = delete;
	ColManager(ColManager&& _Other) noexcept = delete;
	ColManager& operator=(const ColManager& _Other) = delete;
	ColManager& operator=(ColManager&& _Other) noexcept = delete;
	void PlusCollisionValue();
	void MinusCollisionValue();

	int GetCollisionValue()
	{
		return CollisionValue;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:
	int CollisionValue = 0;
	int NextCollisionValue = 0;
};

