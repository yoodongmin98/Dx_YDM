#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class TextActor1 : public G_ActorBase
{
public:
	TextActor1();
	~TextActor1();

	TextActor1(const TextActor1& _Other) = delete;
	TextActor1(TextActor1&& _Other) noexcept = delete;
	TextActor1& operator=(const TextActor1& _Other) = delete;
	TextActor1& operator=(TextActor1&& _Other) noexcept = delete;

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
};
