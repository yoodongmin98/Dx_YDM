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

	GameEngineSoundPlayer Sound;
	GameEngineSoundPlayer Sound2;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteCallings;
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteSpeakings;

	std::shared_ptr<class GameEngineCollision> SkiteCallingCollision;

	std::shared_ptr<class Chain> ChainPtr;
	float LiveTime = 3.0f;

	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
};

