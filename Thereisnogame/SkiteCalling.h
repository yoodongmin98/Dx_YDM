#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SkiteCalling : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteCalling();
	~SkiteCalling();

	// delete Function
	SkiteCalling(const SkiteCalling& _Other) = delete;
	SkiteCalling(SkiteCalling&& _Other) noexcept = delete;
	SkiteCalling& operator=(const SkiteCalling& _Other) = delete;
	SkiteCalling& operator=(SkiteCalling&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteCallings;
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteSpeakings;

	std::shared_ptr<class GameEngineCollision> SkiteCallingCollision;

	std::shared_ptr<class Chain> ChainPtr;
	float LiveTime = 1.0f;
};

