#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class N_TitleMetal : public G_ActorBase
{
public:
	N_TitleMetal();
	~N_TitleMetal();

	N_TitleMetal(const N_TitleMetal& _Other) = delete;
	N_TitleMetal(N_TitleMetal&& _Other) noexcept = delete;
	N_TitleMetal& operator=(const N_TitleMetal& _Other) = delete;
	N_TitleMetal& operator=(N_TitleMetal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> N_TitleMetals;
	std::shared_ptr<class GameEngineCollision> N_TitleMetalsCollision;
};

