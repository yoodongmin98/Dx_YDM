#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_I : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_I();
	~C_Letter_I();

	// delete Function
	C_Letter_I(const C_Letter_I& _Other) = delete;
	C_Letter_I(C_Letter_I&& _Other) noexcept = delete;
	C_Letter_I& operator=(const C_Letter_I& _Other) = delete;
	C_Letter_I& operator=(C_Letter_I&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_I;
};

