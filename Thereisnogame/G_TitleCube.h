#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class G_TitleCube : public G_ActorBase
{
public:
	G_TitleCube();
	~G_TitleCube();

	G_TitleCube(const G_TitleCube& _Other) = delete;
	G_TitleCube(G_TitleCube&& _Other) noexcept = delete;
	G_TitleCube& operator=(const G_TitleCube& _Other) = delete;
	G_TitleCube& operator=(G_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> G_TitleCubes;
	std::shared_ptr<class GameEngineCollision> G_TitleCubesCollision;
};

