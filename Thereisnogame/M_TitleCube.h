#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class M_TitleCube : public G_ActorBase
{
public:
	M_TitleCube();
	~M_TitleCube();

	M_TitleCube(const M_TitleCube& _Other) = delete;
	M_TitleCube(M_TitleCube&& _Other) noexcept = delete;
	M_TitleCube& operator=(const M_TitleCube& _Other) = delete;
	M_TitleCube& operator=(M_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> M_TitleCubes;
	std::shared_ptr<class GameEngineCollision> M_TitleCubesCollision;
};

