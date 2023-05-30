#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class O_TitleCube : public G_ActorBase
{
public:
	O_TitleCube();
	~O_TitleCube();

	O_TitleCube(const O_TitleCube& _Other) = delete;
	O_TitleCube(O_TitleCube&& _Other) noexcept = delete;
	O_TitleCube& operator=(const O_TitleCube& _Other) = delete;
	O_TitleCube& operator=(O_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> O_TitleCubes;
	std::shared_ptr<class GameEngineCollision> O_TitleCubesCollision;
};

