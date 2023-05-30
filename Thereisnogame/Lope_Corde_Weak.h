#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Lope_Corde_Weak : public G_ActorBase
{
public:
	Lope_Corde_Weak();
	~Lope_Corde_Weak();

	Lope_Corde_Weak(const Lope_Corde_Weak& _Other) = delete;
	Lope_Corde_Weak(Lope_Corde_Weak&& _Other) noexcept = delete;
	Lope_Corde_Weak& operator=(const Lope_Corde_Weak& _Other) = delete;
	Lope_Corde_Weak& operator=(Lope_Corde_Weak&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Lope_Corde_Weaks;
	std::shared_ptr<class GameEngineCollision> Lope_Corde_WeaksCollision;
};

