#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class T_TitleMetal : public G_ActorBase
{
public:
	T_TitleMetal();
	~T_TitleMetal();

	T_TitleMetal(const T_TitleMetal& _Other) = delete;
	T_TitleMetal(T_TitleMetal&& _Other) noexcept = delete;
	T_TitleMetal& operator=(const T_TitleMetal& _Other) = delete;
	T_TitleMetal& operator=(T_TitleMetal&& _Other) noexcept = delete;

	void BeforeRoshambo();
	void DeathandCreateScreenT();

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> T_TitleMetals;
	std::shared_ptr<class GameEngineCollision> T_TitleMetalsCollision;
	std::shared_ptr<class TitleMetal> TitleMetalPtr;
};

