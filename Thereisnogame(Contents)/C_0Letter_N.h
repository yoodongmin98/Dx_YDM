#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_N : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_N();
	~C_Letter_N();

	// delete Function
	C_Letter_N(const C_Letter_N& _Other) = delete;
	C_Letter_N(C_Letter_N&& _Other) noexcept = delete;
	C_Letter_N& operator=(const C_Letter_N& _Other) = delete;
	C_Letter_N& operator=(C_Letter_N&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_N;
};

