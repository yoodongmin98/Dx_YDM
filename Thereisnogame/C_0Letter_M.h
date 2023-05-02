#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_M : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_M();
	~C_Letter_M();

	// delete Function
	C_Letter_M(const C_Letter_M& _Other) = delete;
	C_Letter_M(C_Letter_M&& _Other) noexcept = delete;
	C_Letter_M& operator=(const C_Letter_M& _Other) = delete;
	C_Letter_M& operator=(C_Letter_M&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_M;
};

