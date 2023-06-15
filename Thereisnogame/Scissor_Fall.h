#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

class ScissorDeath : public S_ActorBase
{
public:
	ScissorDeath();
	~ScissorDeath();

	ScissorDeath(const ScissorDeath& _Other) = delete;
	ScissorDeath(ScissorDeath&& _Other) noexcept = delete;
	ScissorDeath& operator=(const ScissorDeath& _Other) = delete;
	ScissorDeath& operator=(ScissorDeath&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ScissorDeaths;
};

