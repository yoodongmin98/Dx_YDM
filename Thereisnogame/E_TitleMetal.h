#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class E_TitleMetal : public G_ActorBase
{
public:
	E_TitleMetal();
	~E_TitleMetal();

	E_TitleMetal(const E_TitleMetal& _Other) = delete;
	E_TitleMetal(E_TitleMetal&& _Other) noexcept = delete;
	E_TitleMetal& operator=(const E_TitleMetal& _Other) = delete;
	E_TitleMetal& operator=(E_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> E_TitleMetals;
	std::shared_ptr<class GameEngineCollision> E_TitleMetalsCollision;
};

