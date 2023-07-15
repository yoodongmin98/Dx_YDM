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

	void SoundAndText(float _DeltaTime);
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> T_TitleMetals;
	std::shared_ptr<class GameEngineCollision> T_TitleMetalsCollision;
	std::shared_ptr<class TitleMetal> TitleMetalPtr;

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
	std::shared_ptr<class GameEngineFontRenderer> Font6;
	std::shared_ptr<class GameEngineFontRenderer> Font7;
	std::shared_ptr<class GameEngineFontRenderer> Font8;
	std::shared_ptr<class GameEngineFontRenderer> Font9;
	std::shared_ptr<class GameEngineFontRenderer> Font10;
	std::shared_ptr<class GameEngineFontRenderer> Font11;
	std::shared_ptr<class GameEngineFontRenderer> Font12;
	std::shared_ptr<class GameEngineFontRenderer> Font13;
	std::shared_ptr<class GameEngineFontRenderer> Font14;
	std::shared_ptr<class GameEngineFontRenderer> Font15;
	std::shared_ptr<class GameEngineFontRenderer> Font16;
	std::shared_ptr<class GameEngineFontRenderer> Font17;
	std::shared_ptr<class GameEngineFontRenderer> Font18;
	std::shared_ptr<class GameEngineFontRenderer> Font19;
	std::shared_ptr<class GameEngineFontRenderer> Font20;

	float SoundTime = 0.0f;
};

