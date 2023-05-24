#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SquirrelCloud_Crack : public G_ActorBase
{
public:
	// constrcuter destructer
	SquirrelCloud_Crack();
	~SquirrelCloud_Crack();

	// delete Function
	SquirrelCloud_Crack(const SquirrelCloud_Crack& _Other) = delete;
	SquirrelCloud_Crack(SquirrelCloud_Crack&& _Other) noexcept = delete;
	SquirrelCloud_Crack& operator=(const SquirrelCloud_Crack& _Other) = delete;
	SquirrelCloud_Crack& operator=(SquirrelCloud_Crack&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelCloud_Cracks;
};

