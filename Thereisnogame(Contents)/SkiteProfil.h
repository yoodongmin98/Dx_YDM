#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SkiteProfil : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteProfil();
	~SkiteProfil();

	// delete Function
	SkiteProfil(const SkiteProfil& _Other) = delete;
	SkiteProfil(SkiteProfil&& _Other) noexcept = delete;
	SkiteProfil& operator=(const SkiteProfil& _Other) = delete;
	SkiteProfil& operator=(SkiteProfil&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteProfils;


};

