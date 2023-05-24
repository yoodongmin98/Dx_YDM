#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// Ό³Έν :
class Decapsuleur : public S_ActorBase
{
public:
	// constrcuter destructer
	Decapsuleur();
	~Decapsuleur();

	// delete Function
	Decapsuleur(const Decapsuleur& _Other) = delete;
	Decapsuleur(Decapsuleur&& _Other) noexcept = delete;
	Decapsuleur& operator=(const Decapsuleur& _Other) = delete;
	Decapsuleur& operator=(Decapsuleur&& _Other) noexcept = delete;

	void CollisionDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Decapsuleurs;
	std::shared_ptr<class GameEngineSpriteRenderer> Decapsuleurs_overlap;

	std::shared_ptr<class GameEngineCollision> DecapsuleursCollision;
};

