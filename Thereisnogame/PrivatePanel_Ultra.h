#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PrivatePanel_Ultra : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivatePanel_Ultra();
	~PrivatePanel_Ultra();

	// delete Function
	PrivatePanel_Ultra(const PrivatePanel_Ultra& _Other) = delete;
	PrivatePanel_Ultra(PrivatePanel_Ultra&& _Other) noexcept = delete;
	PrivatePanel_Ultra& operator=(const PrivatePanel_Ultra& _Other) = delete;
	PrivatePanel_Ultra& operator=(PrivatePanel_Ultra&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivatePanel_Ultras;
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateTopPanels;

	std::shared_ptr<class BoxCroix_Music> Croix;

};

