#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_English : public G_ActorBase
{
public:
	// constrcuter destructer
	F_English();
	~F_English();

	// delete Function
	F_English(const F_English& _Other) = delete;
	F_English(F_English&& _Other) noexcept = delete;
	F_English& operator=(const F_English& _Other) = delete;
	F_English& operator=(F_English&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Englishs;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;
};

