#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_Sissor : public G_ActorBase
{
public:
	R_Sissor();
	~R_Sissor();

	R_Sissor(const R_Sissor& _Other) = delete;
	R_Sissor(R_Sissor&& _Other) noexcept = delete;
	R_Sissor& operator=(const R_Sissor& _Other) = delete;
	R_Sissor& operator=(R_Sissor&& _Other) noexcept = delete;

	void Up();
	void StateClickCheck();
	void SetBool()
	{
		R_SissorBool = true;
		R_SissorClick = false;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_Sissors;
	std::shared_ptr<class GameEngineCollision> R_SissorsCollision;
	bool IsPos = false;
	bool R_SissorBool = true;
	bool R_SissorClick = false;
};

