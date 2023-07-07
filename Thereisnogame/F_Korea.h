#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Korea : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Korea();
	~F_Korea();

	// delete Function
	F_Korea(const F_Korea& _Other) = delete;
	F_Korea(F_Korea&& _Other) noexcept = delete;
	F_Korea& operator=(const F_Korea& _Other) = delete;
	F_Korea& operator=(F_Korea&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	GameEngineSoundPlayer Sound;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Koreas;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_KoreasCollision;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

