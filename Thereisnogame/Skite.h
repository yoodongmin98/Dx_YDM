#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Skite : public G_ActorBase
{
public:
	// constrcuter destructer
	Skite();
	~Skite();

	// delete Function
	Skite(const Skite& _Other) = delete;
	Skite(Skite&& _Other) noexcept = delete;
	Skite& operator=(const Skite& _Other) = delete;
	Skite& operator=(Skite&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Skites;
	
	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
};

