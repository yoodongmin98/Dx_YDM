#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class CoffreFortPanel : public G_ActorBase
{
public:
	CoffreFortPanel();
	~CoffreFortPanel();

	CoffreFortPanel(const CoffreFortPanel& _Other) = delete;
	CoffreFortPanel(CoffreFortPanel&& _Other) noexcept = delete;
	CoffreFortPanel& operator=(const CoffreFortPanel& _Other) = delete;
	CoffreFortPanel& operator=(CoffreFortPanel&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CoffreFortPanels;
};

