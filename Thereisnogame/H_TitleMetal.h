#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class H_TitleMetal : public G_ActorBase
{
public:
	H_TitleMetal();
	~H_TitleMetal();

	H_TitleMetal(const H_TitleMetal& _Other) = delete;
	H_TitleMetal(H_TitleMetal&& _Other) noexcept = delete;
	H_TitleMetal& operator=(const H_TitleMetal& _Other) = delete;
	H_TitleMetal& operator=(H_TitleMetal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> H_TitleMetals;
	std::shared_ptr<class GameEngineCollision> H_TitleMetalsCollision;
};

