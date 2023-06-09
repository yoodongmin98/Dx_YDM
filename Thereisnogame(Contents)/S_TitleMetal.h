#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class S_TitleMetal : public G_ActorBase
{
public:
	S_TitleMetal();
	~S_TitleMetal();

	S_TitleMetal(const S_TitleMetal& _Other) = delete;
	S_TitleMetal(S_TitleMetal&& _Other) noexcept = delete;
	S_TitleMetal& operator=(const S_TitleMetal& _Other) = delete;
	S_TitleMetal& operator=(S_TitleMetal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> S_TitleMetals;
	std::shared_ptr<class GameEngineCollision> S_TitleMetalsCollision;
};

