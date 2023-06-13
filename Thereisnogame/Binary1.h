#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Binary1 : public G_ActorBase
{
public:
	Binary1();
	~Binary1();

	Binary1(const Binary1& _Other) = delete;
	Binary1(Binary1&& _Other) noexcept = delete;
	Binary1& operator=(const Binary1& _Other) = delete;
	Binary1& operator=(Binary1&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Binary1s;
};

