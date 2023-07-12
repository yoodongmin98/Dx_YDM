#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// Ό³Έν :
class SquirrelKeyMiddle : public S_ActorBase
{
public:
	// constrcuter destructer
	SquirrelKeyMiddle();
	~SquirrelKeyMiddle();

	// delete Function
	SquirrelKeyMiddle(const SquirrelKeyMiddle& _Other) = delete;
	SquirrelKeyMiddle(SquirrelKeyMiddle&& _Other) noexcept = delete;
	SquirrelKeyMiddle& operator=(const SquirrelKeyMiddle& _Other) = delete;
	SquirrelKeyMiddle& operator=(SquirrelKeyMiddle&& _Other) noexcept = delete;

	void CollisionInteractableCheck();
	void SoundCheck(float _DeltaTime);
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelKeyMiddles;
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelKeyMiddle_overlap;

	std::shared_ptr<class GameEngineCollision> SquirrelKeyMiddleCollision;

	float BoolTime = 0.0f;
};

