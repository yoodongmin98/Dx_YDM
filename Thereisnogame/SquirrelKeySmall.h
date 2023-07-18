#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// Ό³Έν :
class SquirrelKeySmall : public S_ActorBase
{
public:
	// constrcuter destructer
	SquirrelKeySmall();
	~SquirrelKeySmall();

	// delete Function
	SquirrelKeySmall(const SquirrelKeySmall& _Other) = delete;
	SquirrelKeySmall(SquirrelKeySmall&& _Other) noexcept = delete;
	SquirrelKeySmall& operator=(const SquirrelKeySmall& _Other) = delete;
	SquirrelKeySmall& operator=(SquirrelKeySmall&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelKeySmalls;
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelKeySmall_overlap;

	std::shared_ptr<class GameEngineCollision> SquirrelKeySmallCollision;

	float LevelChangeTime = 0.0f;
	bool LevelChangeBool = true;
};

