#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class CoffreFortHandle : public G_ActorBase
{
public:
	CoffreFortHandle();
	~CoffreFortHandle();

	CoffreFortHandle(const CoffreFortHandle& _Other) = delete;
	CoffreFortHandle(CoffreFortHandle&& _Other) noexcept = delete;
	CoffreFortHandle& operator=(const CoffreFortHandle& _Other) = delete;
	CoffreFortHandle& operator=(CoffreFortHandle&& _Other) noexcept = delete;

	void HandleRotateCheck(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CoffreFortHandles;
	std::shared_ptr<class GameEngineSpriteRenderer> CoffreFortHandlesShadow;
	std::shared_ptr<class GameEngineCollision> CoffreFortHandlesCollision;

	float Force = 0.0f;
};

