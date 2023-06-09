#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class LoadErrorPaper : public G_ActorBase
{
public:
	LoadErrorPaper();
	~LoadErrorPaper();

	LoadErrorPaper(const LoadErrorPaper& _Other) = delete;
	LoadErrorPaper(LoadErrorPaper&& _Other) noexcept = delete;
	LoadErrorPaper& operator=(const LoadErrorPaper& _Other) = delete;
	LoadErrorPaper& operator=(LoadErrorPaper&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LoadErrorPapers;
	std::shared_ptr<class GameEngineCollision> LoadErrorPapersCollision;
};

