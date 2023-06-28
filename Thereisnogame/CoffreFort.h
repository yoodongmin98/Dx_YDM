#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class CoffreFort : public G_ActorBase
{
public:
	CoffreFort();
	~CoffreFort();

	CoffreFort(const CoffreFort& _Other) = delete;
	CoffreFort(CoffreFort&& _Other) noexcept = delete;
	CoffreFort& operator=(const CoffreFort& _Other) = delete;
	CoffreFort& operator=(CoffreFort&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CoffreForts;
};

