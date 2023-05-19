#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SuperPrivate : public G_ActorBase
{
public:
	// constrcuter destructer
	SuperPrivate();
	~SuperPrivate();

	// delete Function
	SuperPrivate(const SuperPrivate& _Other) = delete;
	SuperPrivate(SuperPrivate&& _Other) noexcept = delete;
	SuperPrivate& operator=(const SuperPrivate& _Other) = delete;
	SuperPrivate& operator=(SuperPrivate&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SuperPrivates;
	std::shared_ptr<class GameEngineCollision> SuperPrivatesCollision;

};

