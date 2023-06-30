#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// Ό³Έν :
class Cog : public S_ActorBase
{
public:
	// constrcuter destructer
	Cog();
	~Cog();

	// delete Function
	Cog(const Cog& _Other) = delete;
	Cog(Cog&& _Other) noexcept = delete;
	Cog& operator=(const Cog& _Other) = delete;
	Cog& operator=(Cog&& _Other) noexcept = delete;

	void CogDeathandInterCheck();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cogs;
	std::shared_ptr<class GameEngineSpriteRenderer> Cogs_Overlap;

	std::shared_ptr<class GameEngineCollision> CogCollision;
};

