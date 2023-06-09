#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class M_TitleMetal : public G_ActorBase
{
public:
	M_TitleMetal();
	~M_TitleMetal();

	M_TitleMetal(const M_TitleMetal& _Other) = delete;
	M_TitleMetal(M_TitleMetal&& _Other) noexcept = delete;
	M_TitleMetal& operator=(const M_TitleMetal& _Other) = delete;
	M_TitleMetal& operator=(M_TitleMetal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> M_TitleMetals;
	std::shared_ptr<class GameEngineCollision> M_TitleMetalsCollision;
};

