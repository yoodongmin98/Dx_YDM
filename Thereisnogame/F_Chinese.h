#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Chinese : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Chinese();
	~F_Chinese();

	// delete Function
	F_Chinese(const F_Chinese& _Other) = delete;
	F_Chinese(F_Chinese&& _Other) noexcept = delete;
	F_Chinese& operator=(const F_Chinese& _Other) = delete;
	F_Chinese& operator=(F_Chinese&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Chineses;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;

	std::shared_ptr<class GameEngineCollision> F_ChinesesCollision;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

