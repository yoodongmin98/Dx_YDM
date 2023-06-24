#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class RE_TitleCube : public G_ActorBase
{
public:
	RE_TitleCube();
	~RE_TitleCube();

	RE_TitleCube(const RE_TitleCube& _Other) = delete;
	RE_TitleCube(RE_TitleCube&& _Other) noexcept = delete;
	RE_TitleCube& operator=(const RE_TitleCube& _Other) = delete;
	RE_TitleCube& operator=(RE_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	void BallCheckEvent() override;
private:
	bool DeathCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> RE_TitleCubes;
	std::shared_ptr<class GameEngineCollision> RE_TitleCubesCollision;
};

