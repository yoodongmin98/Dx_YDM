#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class S_TitleCube : public G_ActorBase
{
public:
	S_TitleCube();
	~S_TitleCube();

	S_TitleCube(const S_TitleCube& _Other) = delete;
	S_TitleCube(S_TitleCube&& _Other) noexcept = delete;
	S_TitleCube& operator=(const S_TitleCube& _Other) = delete;
	S_TitleCube& operator=(S_TitleCube&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	void BallCheckEvent() override;
private:
	bool DeathCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> S_TitleCubes;
	std::shared_ptr<class GameEngineCollision> S_TitleCubesCollision;
};

