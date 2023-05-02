#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_H : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_H();
	~C_Letter_H();

	// delete Function
	C_Letter_H(const C_Letter_H& _Other) = delete;
	C_Letter_H(C_Letter_H&& _Other) noexcept = delete;
	C_Letter_H& operator=(const C_Letter_H& _Other) = delete;
	C_Letter_H& operator=(C_Letter_H&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_H;
};

