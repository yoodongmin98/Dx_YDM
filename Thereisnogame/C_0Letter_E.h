#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class C_Letter_E : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_E();
	~C_Letter_E();

	// delete Function
	C_Letter_E(const C_Letter_E& _Other) = delete;
	C_Letter_E(C_Letter_E&& _Other) noexcept = delete;
	C_Letter_E& operator=(const C_Letter_E& _Other) = delete;
	C_Letter_E& operator=(C_Letter_E&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_E;
};

