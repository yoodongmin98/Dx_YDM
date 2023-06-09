#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Lope_Chain : public G_ActorBase
{
public:
	Lope_Chain();
	~Lope_Chain();

	Lope_Chain(const Lope_Chain& _Other) = delete;
	Lope_Chain(Lope_Chain&& _Other) noexcept = delete;
	Lope_Chain& operator=(const Lope_Chain& _Other) = delete;
	Lope_Chain& operator=(Lope_Chain&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Lope_Chains;
	std::shared_ptr<class GameEngineCollision> Lope_ChainsCollision;
};

