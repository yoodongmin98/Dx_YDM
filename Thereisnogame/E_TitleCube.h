#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class E_TitleCube : public G_ActorBase
{
public:
	E_TitleCube();
	~E_TitleCube();

	E_TitleCube(const E_TitleCube& _Other) = delete;
	E_TitleCube(E_TitleCube&& _Other) noexcept = delete;
	E_TitleCube& operator=(const E_TitleCube& _Other) = delete;
	E_TitleCube& operator=(E_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	void BallCheckEvent() override;
private:
	bool DeathCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> E_TitleCubes;
	std::shared_ptr<class GameEngineCollision> E_TitleCubesCollision;
};

