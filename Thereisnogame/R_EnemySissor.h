#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_EnemySissor : public G_ActorBase
{
public:
	R_EnemySissor();
	~R_EnemySissor();

	R_EnemySissor(const R_EnemySissor& _Other) = delete;
	R_EnemySissor(R_EnemySissor&& _Other) noexcept = delete;
	R_EnemySissor& operator=(const R_EnemySissor& _Other) = delete;
	R_EnemySissor& operator=(R_EnemySissor&& _Other) noexcept = delete;

	void Up();
	void RenderOnoffCheck();
	void CreateScissor();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_EnemySissors;
	std::shared_ptr<class GameEngineSpriteRenderer> R_EnemySissorsNone;
	std::shared_ptr<class GameEngineCollision> R_EnemySissorsCollision;
	bool IsPos = false;

	std::shared_ptr<class Scissor> ScissorPtr;
};

