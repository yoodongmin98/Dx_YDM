#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BackSqirrelKey : public G_ActorBase
{
public:
	// constrcuter destructer
	BackSqirrelKey();
	~BackSqirrelKey();

	// delete Function
	BackSqirrelKey(const BackSqirrelKey& _Other) = delete;
	BackSqirrelKey(BackSqirrelKey&& _Other) noexcept = delete;
	BackSqirrelKey& operator=(const BackSqirrelKey& _Other) = delete;
	BackSqirrelKey& operator=(BackSqirrelKey&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BackSqirrelKeys;
	std::shared_ptr<class GameEngineCollision> BackSqirrelKeysCollision;

	std::shared_ptr<class SquirrelCloud_Need> SquirrelCloud_NeedPtr;

};

