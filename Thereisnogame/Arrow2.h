#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Arrow2 : public G_ActorBase
{
public:
	// constrcuter destructer
	Arrow2();
	~Arrow2();

	// delete Function
	Arrow2(const Arrow2& _Other) = delete;
	Arrow2(Arrow2&& _Other) noexcept = delete;
	Arrow2& operator=(const Arrow2& _Other) = delete;
	Arrow2& operator=(Arrow2&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOn;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOff;

	float ArrowBlinkTime = 0.0f;
};

