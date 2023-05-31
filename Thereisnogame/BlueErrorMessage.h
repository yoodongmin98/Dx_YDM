#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class BlueErrorMessage : public G_ActorBase
{
public:
	BlueErrorMessage();
	~BlueErrorMessage();

	BlueErrorMessage(const BlueErrorMessage& _Other) = delete;
	BlueErrorMessage(BlueErrorMessage&& _Other) noexcept = delete;
	BlueErrorMessage& operator=(const BlueErrorMessage& _Other) = delete;
	BlueErrorMessage& operator=(BlueErrorMessage&& _Other) noexcept = delete;
	std::shared_ptr<class FadeEffect> FEffect;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BlueErrorMessages;
};

