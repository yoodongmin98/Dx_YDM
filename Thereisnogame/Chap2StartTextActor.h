#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Chap2StartTextActor : public G_ActorBase
{
public:
	Chap2StartTextActor();
	~Chap2StartTextActor();

	Chap2StartTextActor(const Chap2StartTextActor& _Other) = delete;
	Chap2StartTextActor(Chap2StartTextActor&& _Other) noexcept = delete;
	Chap2StartTextActor& operator=(const Chap2StartTextActor& _Other) = delete;
	Chap2StartTextActor& operator=(Chap2StartTextActor&& _Other) noexcept = delete;

	void SoundAndText(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	float SoundTime = 0.0f;

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
	std::shared_ptr<class GameEngineFontRenderer> Font6;
	std::shared_ptr<class GameEngineFontRenderer> Font7;
	std::shared_ptr<class GameEngineFontRenderer> Font8;
};

