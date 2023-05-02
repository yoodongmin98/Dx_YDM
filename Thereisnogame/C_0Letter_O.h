#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_O : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_O();
	~C_Letter_O();

	// delete Function
	C_Letter_O(const C_Letter_O& _Other) = delete;
	C_Letter_O(C_Letter_O&& _Other) noexcept = delete;
	C_Letter_O& operator=(const C_Letter_O& _Other) = delete;
	C_Letter_O& operator=(C_Letter_O&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_O;
};

