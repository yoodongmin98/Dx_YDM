#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class A_TitleCube : public G_ActorBase
{
public:
	A_TitleCube();
	~A_TitleCube();

	A_TitleCube(const A_TitleCube& _Other) = delete;
	A_TitleCube(A_TitleCube&& _Other) noexcept = delete;
	A_TitleCube& operator=(const A_TitleCube& _Other) = delete;
	A_TitleCube& operator=(A_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> A_TitleCubes;
	std::shared_ptr<class GameEngineCollision> A_TitleCubesCollision;
};

