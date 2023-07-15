#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class ME_TitleMetal : public G_ActorBase
{
public:
	ME_TitleMetal();
	~ME_TitleMetal();

	ME_TitleMetal(const ME_TitleMetal& _Other) = delete;
	ME_TitleMetal(ME_TitleMetal&& _Other) noexcept = delete;
	ME_TitleMetal& operator=(const ME_TitleMetal& _Other) = delete;
	ME_TitleMetal& operator=(ME_TitleMetal&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ME_TitleMetals;
	std::shared_ptr<class GameEngineCollision> ME_TitleMetalsCollision;

	bool StateChangeBool = true;
};

