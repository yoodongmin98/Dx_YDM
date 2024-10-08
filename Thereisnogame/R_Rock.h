#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_Rock : public G_ActorBase
{
public:
	R_Rock();
	~R_Rock();

	R_Rock(const R_Rock& _Other) = delete;
	R_Rock(R_Rock&& _Other) noexcept = delete;
	R_Rock& operator=(const R_Rock& _Other) = delete;
	R_Rock& operator=(R_Rock&& _Other) noexcept = delete;

	void Up();
	void StateClickCheck();
	void SetBool()
	{
		R_RockBool = true;
		R_RockClick = false;
	}

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_Rocks;
	std::shared_ptr<class GameEngineCollision> R_RocksCollision;
	bool IsPos = false;
	bool R_RockBool = true;
	bool R_RockClick = false;
};

