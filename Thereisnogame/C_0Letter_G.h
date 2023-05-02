#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class C_Letter_G : public G_ActorBase
{
public:
	// constrcuter destructer
	C_Letter_G();
	~C_Letter_G();

	// delete Function
	C_Letter_G(const C_Letter_G& _Other) = delete;
	C_Letter_G(C_Letter_G&& _Other) noexcept = delete;
	C_Letter_G& operator=(const C_Letter_G& _Other) = delete;
	C_Letter_G& operator=(C_Letter_G&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:

	std::shared_ptr<class GameEngineSpriteRenderer> Letter_G;
};

