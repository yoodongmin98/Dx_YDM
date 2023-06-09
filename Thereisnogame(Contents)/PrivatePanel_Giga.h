#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PrivatePanel_Giga : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivatePanel_Giga();
	~PrivatePanel_Giga();

	// delete Function
	PrivatePanel_Giga(const PrivatePanel_Giga& _Other) = delete;
	PrivatePanel_Giga(PrivatePanel_Giga&& _Other) noexcept = delete;
	PrivatePanel_Giga& operator=(const PrivatePanel_Giga& _Other) = delete;
	PrivatePanel_Giga& operator=(PrivatePanel_Giga&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivatePanel_Gigas;
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateTopPanels;
};

