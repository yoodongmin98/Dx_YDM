#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MusicNote_Rain : public G_ActorBase
{
public:
	// constrcuter destructer
	MusicNote_Rain();
	~MusicNote_Rain();

	// delete Function
	MusicNote_Rain(const MusicNote_Rain& _Other) = delete;
	MusicNote_Rain(MusicNote_Rain&& _Other) noexcept = delete;
	MusicNote_Rain& operator=(const MusicNote_Rain& _Other) = delete;
	MusicNote_Rain& operator=(MusicNote_Rain&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicNote_Rains;
	std::shared_ptr<class GameEngineCollision> MusicNote_RainsCollision;

};

