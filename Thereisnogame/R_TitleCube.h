#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_TitleCube : public G_ActorBase
{
public:
	R_TitleCube();
	~R_TitleCube();

	R_TitleCube(const R_TitleCube& _Other) = delete;
	R_TitleCube(R_TitleCube&& _Other) noexcept = delete;
	R_TitleCube& operator=(const R_TitleCube& _Other) = delete;
	R_TitleCube& operator=(R_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	void BallCheckEvent() override;
private:
	bool DeathCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> R_TitleCubes;
	std::shared_ptr<class GameEngineCollision> R_TitleCubesCollision;
};

