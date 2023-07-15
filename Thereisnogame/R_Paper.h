#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class R_Paper : public G_ActorBase
{
public:
	R_Paper();
	~R_Paper();

	R_Paper(const R_Paper& _Other) = delete;
	R_Paper(R_Paper&& _Other) noexcept = delete;
	R_Paper& operator=(const R_Paper& _Other) = delete;
	R_Paper& operator=(R_Paper&& _Other) noexcept = delete;

	void Up();
	void StateClickCheck();
	void SetBool()
	{
		R_PaperBool = true;
		R_PaperClick = false;
	}

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> R_Papers;
	std::shared_ptr<class GameEngineCollision> R_PapersCollision;
	bool IsPos = false;
	bool R_PaperBool = true;
	bool R_PaperClick = false;
};

