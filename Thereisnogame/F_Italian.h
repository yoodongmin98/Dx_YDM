#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Italian : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Italian();
	~F_Italian();

	// delete Function
	F_Italian(const F_Italian& _Other) = delete;
	F_Italian(F_Italian&& _Other) noexcept = delete;
	F_Italian& operator=(const F_Italian& _Other) = delete;
	F_Italian& operator=(F_Italian&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Italians;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_ItaliansCollision;
};

