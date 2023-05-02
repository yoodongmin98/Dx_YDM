#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_e2 : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_e2();
	~C_Letter_e2();

	// delete Function
	C_Letter_e2(const C_Letter_e2& _Other) = delete;
	C_Letter_e2(C_Letter_e2&& _Other) noexcept = delete;
	C_Letter_e2& operator=(const C_Letter_e2& _Other) = delete;
	C_Letter_e2& operator=(C_Letter_e2&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_e2;
};

