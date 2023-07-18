#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class StartButton : public G_ActorBase
{
public:
	StartButton();
	~StartButton();

	StartButton(const StartButton& _Other) = delete;
	StartButton(StartButton&& _Other) noexcept = delete;
	StartButton& operator=(const StartButton& _Other) = delete;
	StartButton& operator=(StartButton&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> StartButtons;
	std::shared_ptr<class GameEngineFontRenderer> Font;
};

