#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class DeleteArrow : public G_ActorBase
{
public:
	// constrcuter destructer
	DeleteArrow();
	~DeleteArrow();

	// delete Function
	DeleteArrow(const DeleteArrow& _Other) = delete;
	DeleteArrow(DeleteArrow&& _Other) noexcept = delete;
	DeleteArrow& operator=(const DeleteArrow& _Other) = delete;
	DeleteArrow& operator=(DeleteArrow&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	GameEngineSoundPlayer Sound;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow1;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow2;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow3;
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow4;



};

