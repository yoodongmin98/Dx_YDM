#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class GameBall_TitleCube : public G_ActorBase
{
public:
	GameBall_TitleCube();
	~GameBall_TitleCube();

	GameBall_TitleCube(const GameBall_TitleCube& _Other) = delete;
	GameBall_TitleCube(GameBall_TitleCube&& _Other) noexcept = delete;
	GameBall_TitleCube& operator=(const GameBall_TitleCube& _Other) = delete;
	GameBall_TitleCube& operator=(GameBall_TitleCube&& _Other) noexcept = delete;

	void StartRigidBody();
	void CollisionInterCheck(G_RigidBody* _Rigids);
	void CubeCrashCheck(G_RigidBody* _Rigids);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> GameBall_TitleCubes;
	std::shared_ptr<class GameEngineCollision> GameBall_TitleCubesCollisionU;
	std::shared_ptr<class GameEngineCollision> GameBall_TitleCubesCollisionD;
	std::shared_ptr<class GameEngineCollision> GameBall_TitleCubesCollisionL;
	std::shared_ptr<class GameEngineCollision> GameBall_TitleCubesCollisionR;

	float InterBoolTime = 0.0f;
	bool InterBool = true;
};

