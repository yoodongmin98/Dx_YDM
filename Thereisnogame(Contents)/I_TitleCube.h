#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class I_TitleCube : public G_ActorBase
{
public:
	I_TitleCube();
	~I_TitleCube();

	I_TitleCube(const I_TitleCube& _Other) = delete;
	I_TitleCube(I_TitleCube&& _Other) noexcept = delete;
	I_TitleCube& operator=(const I_TitleCube& _Other) = delete;
	I_TitleCube& operator=(I_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> I_TitleCubes;
	std::shared_ptr<class GameEngineCollision> I_TitleCubesCollision;
};

