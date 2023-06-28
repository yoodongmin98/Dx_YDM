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
	void PanelInterCheck(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CoffreFortPanels;
	std::shared_ptr<class GameEngineSpriteRenderer> TestCoffreFortPanels;
	std::shared_ptr<class GameEngineCollision> CoffreFortPanelsColliision;

	bool PanelOpen = false;
	float PanelTime = 0.0f;

	float4 StartPosX = float4::Zero;
	float4 EndPosX = float4::Zero;
};

