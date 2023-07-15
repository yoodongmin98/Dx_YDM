#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class I_TitleMetal : public G_ActorBase
{
public:
	I_TitleMetal();
	~I_TitleMetal();

	I_TitleMetal(const I_TitleMetal& _Other) = delete;
	I_TitleMetal(I_TitleMetal&& _Other) noexcept = delete;
	I_TitleMetal& operator=(const I_TitleMetal& _Other) = delete;
	I_TitleMetal& operator=(I_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> I_TitleMetals;
	std::shared_ptr<class GameEngineCollision> I_TitleMetalsCollision;
};

