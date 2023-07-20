#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PlaySmallArrow : public G_ActorBase
{
public:
	// constrcuter destructer
	PlaySmallArrow();
	~PlaySmallArrow();

	// delete Function
	PlaySmallArrow(const PlaySmallArrow& _Other) = delete;
	PlaySmallArrow(PlaySmallArrow&& _Other) noexcept = delete;
	PlaySmallArrow& operator=(const PlaySmallArrow& _Other) = delete;
	PlaySmallArrow& operator=(PlaySmallArrow&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	GameEngineSoundPlayer Sound;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Arrow;
	


};

