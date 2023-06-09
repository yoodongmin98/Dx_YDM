#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Panel_Continue : public G_ActorBase
{
public:
	// constrcuter destructer
	Panel_Continue();
	~Panel_Continue();

	// delete Function
	Panel_Continue(const Panel_Continue& _Other) = delete;
	Panel_Continue(Panel_Continue&& _Other) noexcept = delete;
	Panel_Continue& operator=(const Panel_Continue& _Other) = delete;
	Panel_Continue& operator=(Panel_Continue&& _Other) noexcept = delete;

	void ZRotations(float _DeltaTime);
	void RZRotations(float _DeltaTime);
	

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Panel_Continues;
	std::shared_ptr<class GameEngineCollision> Panel_ContinuesCollision;
};

