#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class LoadBarBack : public G_ActorBase
{
public:
	LoadBarBack();
	~LoadBarBack();

	LoadBarBack(const LoadBarBack& _Other) = delete;
	LoadBarBack(LoadBarBack&& _Other) noexcept = delete;
	LoadBarBack& operator=(const LoadBarBack& _Other) = delete;
	LoadBarBack& operator=(LoadBarBack&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LoadBarBacks;
	std::shared_ptr<class GameEngineCollision> LoadBarBacksCollision;
};

