#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MediaPause : public G_ActorBase
{
public:
	static MediaPause* MainMediaPause;
	// constrcuter destructer
	MediaPause();
	~MediaPause();

	// delete Function
	MediaPause(const MediaPause& _Other) = delete;
	MediaPause(MediaPause&& _Other) noexcept = delete;
	MediaPause& operator=(const MediaPause& _Other) = delete;
	MediaPause& operator=(MediaPause&& _Other) noexcept = delete;

	void SetMediaPauseoff();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPauses;
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPauseoffs;
	std::shared_ptr<class GameEngineCollision> MediaPausesCollision;
};

