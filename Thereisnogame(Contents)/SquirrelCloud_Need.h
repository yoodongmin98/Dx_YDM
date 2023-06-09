#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SquirrelCloud_Need : public G_ActorBase
{
public:
	// constrcuter destructer
	SquirrelCloud_Need();
	~SquirrelCloud_Need();

	// delete Function
	SquirrelCloud_Need(const SquirrelCloud_Need& _Other) = delete;
	SquirrelCloud_Need(SquirrelCloud_Need&& _Other) noexcept = delete;
	SquirrelCloud_Need& operator=(const SquirrelCloud_Need& _Other) = delete;
	SquirrelCloud_Need& operator=(SquirrelCloud_Need&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelCloud_Needs;
};

