#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Excla_TitleCube : public G_ActorBase
{
public:
	Excla_TitleCube();
	~Excla_TitleCube();

	Excla_TitleCube(const Excla_TitleCube& _Other) = delete;
	Excla_TitleCube(Excla_TitleCube&& _Other) noexcept = delete;
	Excla_TitleCube& operator=(const Excla_TitleCube& _Other) = delete;
	Excla_TitleCube& operator=(Excla_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Excla_TitleCubes;
	std::shared_ptr<class GameEngineCollision> Excla_TitleCubesCollision;
};

