#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Japan : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Japan();
	~F_Japan();

	// delete Function
	F_Japan(const F_Japan& _Other) = delete;
	F_Japan(F_Japan&& _Other) noexcept = delete;
	F_Japan& operator=(const F_Japan& _Other) = delete;
	F_Japan& operator=(F_Japan&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Japans;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_JapansCollision;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

