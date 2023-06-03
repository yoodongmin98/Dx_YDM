#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

class Raquette_TitleCube : public S_ActorBase
{
public:
	Raquette_TitleCube();
	~Raquette_TitleCube();

	Raquette_TitleCube(const Raquette_TitleCube& _Other) = delete;
	Raquette_TitleCube(Raquette_TitleCube&& _Other) noexcept = delete;
	Raquette_TitleCube& operator=(const Raquette_TitleCube& _Other) = delete;
	Raquette_TitleCube& operator=(Raquette_TitleCube&& _Other) noexcept = delete;

	void CatchMoveCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Raquette_TitleCubes;
	std::shared_ptr<class GameEngineCollision> Raquette_TitleCubesCollision;

};

