#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class N_TitleCube : public G_ActorBase
{
public:
	N_TitleCube();
	~N_TitleCube();

	N_TitleCube(const N_TitleCube& _Other) = delete;
	N_TitleCube(N_TitleCube&& _Other) noexcept = delete;
	N_TitleCube& operator=(const N_TitleCube& _Other) = delete;
	N_TitleCube& operator=(N_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> N_TitleCubes;
	std::shared_ptr<class GameEngineCollision> N_TitleCubesCollision;
};

