#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class ETC_TitleMetal : public G_ActorBase
{
public:
	ETC_TitleMetal();
	~ETC_TitleMetal();

	ETC_TitleMetal(const ETC_TitleMetal& _Other) = delete;
	ETC_TitleMetal(ETC_TitleMetal&& _Other) noexcept = delete;
	ETC_TitleMetal& operator=(const ETC_TitleMetal& _Other) = delete;
	ETC_TitleMetal& operator=(ETC_TitleMetal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ETC_TitleMetals;
	std::shared_ptr<class GameEngineCollision> ETC_TitleMetalsCollision;
};

