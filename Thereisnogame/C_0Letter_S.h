#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_S : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_S();
	~C_Letter_S();

	// delete Function
	C_Letter_S(const C_Letter_S& _Other) = delete;
	C_Letter_S(C_Letter_S&& _Other) noexcept = delete;
	C_Letter_S& operator=(const C_Letter_S& _Other) = delete;
	C_Letter_S& operator=(C_Letter_S&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_S;
};

