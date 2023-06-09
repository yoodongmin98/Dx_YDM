#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_Dos : public G_ActorBase
{
public:
	static R_Dos* Dos;
	R_Dos();
	~R_Dos();

	R_Dos(const R_Dos& _Other) = delete;
	R_Dos(R_Dos&& _Other) noexcept = delete;
	R_Dos& operator=(const R_Dos& _Other) = delete;
	R_Dos& operator=(R_Dos&& _Other) noexcept = delete;

	void Up();
	void Shake();

	void SetCountClear()
	{
		RotateCount = 0;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_Doss;
	std::shared_ptr<class GameEngineCollision> R_DossCollision;
	bool IsPos = false;
	int RotateCount = 0;
};

