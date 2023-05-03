#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Arrow4 : public G_ActorBase
{
public:
	// constrcuter destructer
	Arrow4();
	~Arrow4();

	// delete Function
	Arrow4(const Arrow4& _Other) = delete;
	Arrow4(Arrow4&& _Other) noexcept = delete;
	Arrow4& operator=(const Arrow4& _Other) = delete;
	Arrow4& operator=(Arrow4&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOn;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOff;

	float ArrowBlinkTime = 0.0f;
};

