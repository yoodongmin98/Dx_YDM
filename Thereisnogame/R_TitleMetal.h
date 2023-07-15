#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_TitleMetal : public G_ActorBase
{
public:
	R_TitleMetal();
	~R_TitleMetal();

	R_TitleMetal(const R_TitleMetal& _Other) = delete;
	R_TitleMetal(R_TitleMetal&& _Other) noexcept = delete;
	R_TitleMetal& operator=(const R_TitleMetal& _Other) = delete;
	R_TitleMetal& operator=(R_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_TitleMetals;
	std::shared_ptr<class GameEngineCollision> R_TitleMetalsCollision;
};

