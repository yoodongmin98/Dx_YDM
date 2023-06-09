#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Arrow1 : public G_ActorBase
{
public:
	// constrcuter destructer
	Arrow1();
	~Arrow1();

	// delete Function
	Arrow1(const Arrow1& _Other) = delete;
	Arrow1(Arrow1&& _Other) noexcept = delete;
	Arrow1& operator=(const Arrow1& _Other) = delete;
	Arrow1& operator=(Arrow1&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOn;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOff;

	float ArrowBlinkTime = 0.0f;
};

