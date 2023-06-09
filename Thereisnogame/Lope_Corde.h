#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Lope_Corde : public G_ActorBase
{
public:
	Lope_Corde();
	~Lope_Corde();

	Lope_Corde(const Lope_Corde& _Other) = delete;
	Lope_Corde(Lope_Corde&& _Other) noexcept = delete;
	Lope_Corde& operator=(const Lope_Corde& _Other) = delete;
	Lope_Corde& operator=(Lope_Corde&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Lope_Cordes;
	std::shared_ptr<class GameEngineCollision> Lope_CordesCollision;
};

