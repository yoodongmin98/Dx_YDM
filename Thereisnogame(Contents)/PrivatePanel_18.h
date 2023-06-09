#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PrivatePanel_18 : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivatePanel_18();
	~PrivatePanel_18();

	// delete Function
	PrivatePanel_18(const PrivatePanel_18& _Other) = delete;
	PrivatePanel_18(PrivatePanel_18&& _Other) noexcept = delete;
	PrivatePanel_18& operator=(const PrivatePanel_18& _Other) = delete;
	PrivatePanel_18& operator=(PrivatePanel_18&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivatePanel_18s;
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateTopPanels;
};

