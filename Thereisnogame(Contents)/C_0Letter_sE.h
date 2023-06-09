#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_sE : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_sE();
	~C_Letter_sE();

	// delete Function
	C_Letter_sE(const C_Letter_sE& _Other) = delete;
	C_Letter_sE(C_Letter_sE&& _Other) noexcept = delete;
	C_Letter_sE& operator=(const C_Letter_sE& _Other) = delete;
	C_Letter_sE& operator=(C_Letter_sE&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_sE;
};

