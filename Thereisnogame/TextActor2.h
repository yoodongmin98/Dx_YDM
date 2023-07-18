#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class TextActor2 : public G_ActorBase
{
public:
	TextActor2();
	~TextActor2();

	TextActor2(const TextActor2& _Other) = delete;
	TextActor2(TextActor2&& _Other) noexcept = delete;
	TextActor2& operator=(const TextActor2& _Other) = delete;
	TextActor2& operator=(TextActor2&& _Other) noexcept = delete;

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

