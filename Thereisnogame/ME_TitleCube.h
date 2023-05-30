#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class ME_TitleCube : public G_ActorBase
{
public:
	ME_TitleCube();
	~ME_TitleCube();

	ME_TitleCube(const ME_TitleCube& _Other) = delete;
	ME_TitleCube(ME_TitleCube&& _Other) noexcept = delete;
	ME_TitleCube& operator=(const ME_TitleCube& _Other) = delete;
	ME_TitleCube& operator=(ME_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ME_TitleCubes;
	std::shared_ptr<class GameEngineCollision> ME_TitleCubesCollision;
};

