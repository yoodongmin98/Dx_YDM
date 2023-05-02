#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_R : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_R();
	~C_Letter_R();

	// delete Function
	C_Letter_R(const C_Letter_R& _Other) = delete;
	C_Letter_R(C_Letter_R&& _Other) noexcept = delete;
	C_Letter_R& operator=(const C_Letter_R& _Other) = delete;
	C_Letter_R& operator=(C_Letter_R&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_R;
};

