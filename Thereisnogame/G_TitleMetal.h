#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class G_TitleMetal : public G_ActorBase
{
public:
	G_TitleMetal();
	~G_TitleMetal();

	G_TitleMetal(const G_TitleMetal& _Other) = delete;
	G_TitleMetal(G_TitleMetal&& _Other) noexcept = delete;
	G_TitleMetal& operator=(const G_TitleMetal& _Other) = delete;
	G_TitleMetal& operator=(G_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> G_TitleMetals;
	std::shared_ptr<class GameEngineCollision> G_TitleMetalsCollision;
};

