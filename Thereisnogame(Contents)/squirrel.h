#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class squirrel : public G_ActorBase
{
public:
	// constrcuter destructer
	squirrel();
	~squirrel();

	// delete Function
	squirrel(const squirrel& _Other) = delete;
	squirrel(squirrel&& _Other) noexcept = delete;
	squirrel& operator=(const squirrel& _Other) = delete;
	squirrel& operator=(squirrel&& _Other) noexcept = delete;

	
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> squirrels;
};

