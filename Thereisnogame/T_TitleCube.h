#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class T_TitleCube : public G_ActorBase
{
public:
	T_TitleCube();
	~T_TitleCube();

	T_TitleCube(const T_TitleCube& _Other) = delete;
	T_TitleCube(T_TitleCube&& _Other) noexcept = delete;
	T_TitleCube& operator=(const T_TitleCube& _Other) = delete;
	T_TitleCube& operator=(T_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	void BallCheckEvent() override;
private:
	bool DeathCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> T_TitleCubes;
	std::shared_ptr<class GameEngineCollision> T_TitleCubesCollision;
};

