#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PrivatePanel : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivatePanel();
	~PrivatePanel();

	// delete Function
	PrivatePanel(const PrivatePanel& _Other) = delete;
	PrivatePanel(PrivatePanel&& _Other) noexcept = delete;
	PrivatePanel& operator=(const PrivatePanel& _Other) = delete;
	PrivatePanel& operator=(PrivatePanel&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivatePanels;
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateTopPanels;

	std::shared_ptr<class BoxCroix> Croix;

};

