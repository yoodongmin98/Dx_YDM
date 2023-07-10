#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Cordon : public G_ActorBase
{
public:
	Cordon();
	~Cordon();

	Cordon(const Cordon& _Other) = delete;
	Cordon(Cordon&& _Other) noexcept = delete;
	Cordon& operator=(const Cordon& _Other) = delete;
	Cordon& operator=(Cordon&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cordons; 
	std::shared_ptr<class GameEngineCollision> CordonsCollision;

	float Values = 600.0f;
	bool MoveValue = true;
	bool CordonMoveBool = true;
};

