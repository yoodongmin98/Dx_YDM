#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class TransparencyActor : public G_ActorBase
{
	//보이지않는 Actor
public:
	TransparencyActor();
	~TransparencyActor();

	TransparencyActor(const TransparencyActor& _Other) = delete;
	TransparencyActor(TransparencyActor&& _Other) noexcept = delete;
	TransparencyActor& operator=(const TransparencyActor& _Other) = delete;
	TransparencyActor& operator=(TransparencyActor&& _Other) noexcept = delete;

	GameEngineTransform* GetRenderTransform()
	{
		return TransparencyActors->GetTransform();
	}

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TransparencyActors;
};

