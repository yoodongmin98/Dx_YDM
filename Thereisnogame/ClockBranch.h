#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockBranch : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockBranch();
	~ClockBranch();

	// delete Function
	ClockBranch(const ClockBranch& _Other) = delete;
	ClockBranch(ClockBranch&& _Other) noexcept = delete;
	ClockBranch& operator=(const ClockBranch& _Other) = delete;
	ClockBranch& operator=(ClockBranch&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockBranchs;
	std::shared_ptr<class GameEngineCollision> ClockBranchsCollision;

	int FallCount = 0;
};

