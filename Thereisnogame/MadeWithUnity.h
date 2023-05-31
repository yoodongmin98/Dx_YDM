#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class MadeWithUnity : public G_ActorBase
{
public:
	MadeWithUnity();
	~MadeWithUnity();

	MadeWithUnity(const MadeWithUnity& _Other) = delete;
	MadeWithUnity(MadeWithUnity&& _Other) noexcept = delete;
	MadeWithUnity& operator=(const MadeWithUnity& _Other) = delete;
	MadeWithUnity& operator=(MadeWithUnity&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MadeWithUnitys;
};

