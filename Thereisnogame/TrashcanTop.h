#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class TrashcanTop : public G_ActorBase
{
public:
	static TrashcanTop* Top;
	// constrcuter destructer
	TrashcanTop();
	~TrashcanTop();

	// delete Function
	TrashcanTop(const TrashcanTop& _Other) = delete;
	TrashcanTop(TrashcanTop&& _Other) noexcept = delete;
	TrashcanTop& operator=(const TrashcanTop& _Other) = delete;
	TrashcanTop& operator=(TrashcanTop&& _Other) noexcept = delete;

	void TrashCanFallandDeathCheck();
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TrashcanTops;
	std::shared_ptr<class GameEngineCollision> TrashcanTopsCollision;

};

