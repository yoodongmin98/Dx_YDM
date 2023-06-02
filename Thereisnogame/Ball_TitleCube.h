#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Ball_TitleCube : public G_ActorBase
{
public:
	Ball_TitleCube();
	~Ball_TitleCube();

	Ball_TitleCube(const Ball_TitleCube& _Other) = delete;
	Ball_TitleCube(Ball_TitleCube&& _Other) noexcept = delete;
	Ball_TitleCube& operator=(const Ball_TitleCube& _Other) = delete;
	Ball_TitleCube& operator=(Ball_TitleCube&& _Other) noexcept = delete;

	void StartRigidBody();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Ball_TitleCubes;
	std::shared_ptr<class GameEngineCollision> Ball_TitleCubesCollision;

	bool UpdateBool = true;
	int BallClickCount = 0;
};

