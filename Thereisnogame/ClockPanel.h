#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockPanel();
	~ClockPanel();

	// delete Function
	ClockPanel(const ClockPanel& _Other) = delete;
	ClockPanel(ClockPanel&& _Other) noexcept = delete;
	ClockPanel& operator=(const ClockPanel& _Other) = delete;
	ClockPanel& operator=(ClockPanel&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockPanels;

};

