#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PinBall_Icon : public G_ActorBase
{
public:
	// constrcuter destructer
	PinBall_Icon();
	~PinBall_Icon();

	// delete Function
	PinBall_Icon(const PinBall_Icon& _Other) = delete;
	PinBall_Icon(PinBall_Icon&& _Other) noexcept = delete;
	PinBall_Icon& operator=(const PinBall_Icon& _Other) = delete;
	PinBall_Icon& operator=(PinBall_Icon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PinBall_Icons;
	std::shared_ptr<class GameEngineCollision> PinBall_IconsCollision;

	std::shared_ptr<class Cup> CupPtr;
};

