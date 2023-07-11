#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_French : public G_ActorBase
{
public:
	// constrcuter destructer
	F_French();
	~F_French();

	// delete Function
	F_French(const F_French& _Other) = delete;
	F_French(F_French&& _Other) noexcept = delete;
	F_French& operator=(const F_French& _Other) = delete;
	F_French& operator=(F_French&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Frenchs;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_FrenchsCollision;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

