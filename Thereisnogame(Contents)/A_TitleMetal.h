#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class A_TitleMetal : public G_ActorBase
{
public:
	A_TitleMetal();
	~A_TitleMetal();

	A_TitleMetal(const A_TitleMetal& _Other) = delete;
	A_TitleMetal(A_TitleMetal&& _Other) noexcept = delete;
	A_TitleMetal& operator=(const A_TitleMetal& _Other) = delete;
	A_TitleMetal& operator=(A_TitleMetal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> A_TitleMetals;
	std::shared_ptr<class GameEngineCollision> A_TitleMetalsCollision;
};

