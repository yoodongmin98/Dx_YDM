#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_EnemyPaper : public G_ActorBase
{
public:
	R_EnemyPaper();
	~R_EnemyPaper();

	R_EnemyPaper(const R_EnemyPaper& _Other) = delete;
	R_EnemyPaper(R_EnemyPaper&& _Other) noexcept = delete;
	R_EnemyPaper& operator=(const R_EnemyPaper& _Other) = delete;
	R_EnemyPaper& operator=(R_EnemyPaper&& _Other) noexcept = delete;

	void Up();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_EnemyPapers;
	std::shared_ptr<class GameEngineCollision> R_EnemyPapersCollision;
	bool IsPos = false;
};

