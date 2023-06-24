#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class H_TitleCube : public G_ActorBase
{
public:
	H_TitleCube();
	~H_TitleCube();

	H_TitleCube(const H_TitleCube& _Other) = delete;
	H_TitleCube(H_TitleCube&& _Other) noexcept = delete;
	H_TitleCube& operator=(const H_TitleCube& _Other) = delete;
	H_TitleCube& operator=(H_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	void BallCheckEvent() override;
private:
	bool DeathCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> H_TitleCubes;
	std::shared_ptr<class GameEngineCollision> H_TitleCubesCollision;
};

