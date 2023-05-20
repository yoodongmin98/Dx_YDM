#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Gigaprivate : public G_ActorBase
{
public:
	// constrcuter destructer
	Gigaprivate();
	~Gigaprivate();

	// delete Function
	Gigaprivate(const Gigaprivate& _Other) = delete;
	Gigaprivate(Gigaprivate&& _Other) noexcept = delete;
	Gigaprivate& operator=(const Gigaprivate& _Other) = delete;
	Gigaprivate& operator=(Gigaprivate&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Gigaprivates;
	std::shared_ptr<class GameEngineCollision> GigaprivatesCollision;
};

