#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class SoundAndTextActor : public G_ActorBase
{
public:
	SoundAndTextActor();
	~SoundAndTextActor();

	SoundAndTextActor(const SoundAndTextActor& _Other) = delete;
	SoundAndTextActor(SoundAndTextActor&& _Other) noexcept = delete;
	SoundAndTextActor& operator=(const SoundAndTextActor& _Other) = delete;
	SoundAndTextActor& operator=(SoundAndTextActor&& _Other) noexcept = delete;

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
	std::shared_ptr<class GameEngineFontRenderer> Font21;
	std::shared_ptr<class GameEngineFontRenderer> Font22;
	std::shared_ptr<class GameEngineFontRenderer> Font23;
	std::shared_ptr<class GameEngineFontRenderer> Font24;
};

