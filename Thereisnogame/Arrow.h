#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Arrow : public G_ActorBase
{
public:
	// constrcuter destructer
	Arrow();
	~Arrow();

	// delete Function
	Arrow(const Arrow& _Other) = delete;
	Arrow(Arrow&& _Other) noexcept = delete;
	Arrow& operator=(const Arrow& _Other) = delete;
	Arrow& operator=(Arrow&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOn;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow_LightOff;


	float ArrowTestTime=0.0f;
};

