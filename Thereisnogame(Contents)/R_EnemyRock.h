#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_EnemyRock : public G_ActorBase
{
public:
	R_EnemyRock();
	~R_EnemyRock();

	R_EnemyRock(const R_EnemyRock& _Other) = delete;
	R_EnemyRock(R_EnemyRock&& _Other) noexcept = delete;
	R_EnemyRock& operator=(const R_EnemyRock& _Other) = delete;
	R_EnemyRock& operator=(R_EnemyRock&& _Other) noexcept = delete;

	void Up();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_EnemyRocks;
	std::shared_ptr<class GameEngineCollision> R_EnemyRocksCollision;
	bool IsPos = false;
};

