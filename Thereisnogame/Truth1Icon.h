#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Truth1Icon : public G_ActorBase
{
public:
	// constrcuter destructer
	Truth1Icon();
	~Truth1Icon();

	// delete Function
	Truth1Icon(const Truth1Icon& _Other) = delete;
	Truth1Icon(Truth1Icon&& _Other) noexcept = delete;
	Truth1Icon& operator=(const Truth1Icon& _Other) = delete;
	Truth1Icon& operator=(Truth1Icon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Truth1Icons;
};

