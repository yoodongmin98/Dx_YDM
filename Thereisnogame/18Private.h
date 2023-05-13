#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Private : public G_ActorBase
{
public:
	// constrcuter destructer
	Private();
	~Private();

	// delete Function
	18Private(const Gigaprivate& _Other) = delete;
	18Private(Gigaprivate&& _Other) noexcept = delete;
	18Private& operator=(const Gigaprivate& _Other) = delete;
	18Private& operator=(Gigaprivate&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Gigaprivates;

};

