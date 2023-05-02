#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_A : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_A();
	~C_Letter_A();

	// delete Function
	C_Letter_A(const C_Letter_A& _Other) = delete;
	C_Letter_A(C_Letter_A&& _Other) noexcept = delete;
	C_Letter_A& operator=(const C_Letter_A& _Other) = delete;
	C_Letter_A& operator=(C_Letter_A&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_A;
};

