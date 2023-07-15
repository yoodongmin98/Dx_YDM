#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class RE_TitleMetal : public G_ActorBase
{
public:
	RE_TitleMetal();
	~RE_TitleMetal();

	RE_TitleMetal(const RE_TitleMetal& _Other) = delete;
	RE_TitleMetal(RE_TitleMetal&& _Other) noexcept = delete;
	RE_TitleMetal& operator=(const RE_TitleMetal& _Other) = delete;
	RE_TitleMetal& operator=(RE_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> RE_TitleMetals;
	std::shared_ptr<class GameEngineCollision> RE_TitleMetalsCollision;
};

