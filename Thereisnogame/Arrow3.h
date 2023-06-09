#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Arrow3 : public G_ActorBase
{
public:
	// constrcuter destructer
	Arrow3();
	~Arrow3();

	// delete Function
	Arrow3(const Arrow3& _Other) = delete;
	Arrow3(Arrow3&& _Other) noexcept = delete;
	Arrow3& operator=(const Arrow3& _Other) = delete;
	Arrow3& operator=(Arrow3&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOn;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOff;

	float ArrowBlinkTime = 0.0f;
};

