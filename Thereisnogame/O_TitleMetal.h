#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class O_TitleMetal : public G_ActorBase
{
public:
	O_TitleMetal();
	~O_TitleMetal();

	O_TitleMetal(const O_TitleMetal& _Other) = delete;
	O_TitleMetal(O_TitleMetal&& _Other) noexcept = delete;
	O_TitleMetal& operator=(const O_TitleMetal& _Other) = delete;
	O_TitleMetal& operator=(O_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> O_TitleMetals;
	std::shared_ptr<class GameEngineCollision> O_TitleMetalsCollision;
};

