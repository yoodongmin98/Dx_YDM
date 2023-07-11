#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class LeftRotate : public G_ActorBase
{
public:
	// constrcuter destructer
	LeftRotate();
	~LeftRotate();

	// delete Function
	LeftRotate(const LeftRotate& _Other) = delete;
	LeftRotate(LeftRotate&& _Other) noexcept = delete;
	LeftRotate& operator=(const LeftRotate& _Other) = delete;
	LeftRotate& operator=(LeftRotate&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftRotates;
	std::shared_ptr<class GameEngineCollision> LeftRotatesCollision;
};

