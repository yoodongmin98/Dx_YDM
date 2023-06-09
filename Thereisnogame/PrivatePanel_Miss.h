#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PrivatePanel_Miss : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivatePanel_Miss();
	~PrivatePanel_Miss();

	// delete Function
	PrivatePanel_Miss(const PrivatePanel_Miss& _Other) = delete;
	PrivatePanel_Miss(PrivatePanel_Miss&& _Other) noexcept = delete;
	PrivatePanel_Miss& operator=(const PrivatePanel_Miss& _Other) = delete;
	PrivatePanel_Miss& operator=(PrivatePanel_Miss&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivatePanel_Misss;
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateTopPanels;
};

