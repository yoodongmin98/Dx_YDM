#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class StartRedPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	StartRedPanel();
	~StartRedPanel();

	// delete Function
	StartRedPanel(const StartRedPanel& _Other) = delete;
	StartRedPanel(StartRedPanel&& _Other) noexcept = delete;
	StartRedPanel& operator=(const StartRedPanel& _Other) = delete;
	StartRedPanel& operator=(StartRedPanel&& _Other) noexcept = delete;

	
protected:
	GameEngineSoundPlayer Sound;
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> StartRedPanels;

	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
};

