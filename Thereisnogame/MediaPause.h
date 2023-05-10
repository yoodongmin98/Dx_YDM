#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class MediaPause : public G_ActorBase
{
public:
	// constrcuter destructer
	MediaPause();
	~MediaPause();

	// delete Function
	MediaPause(const MediaPause& _Other) = delete;
	MediaPause(MediaPause&& _Other) noexcept = delete;
	MediaPause& operator=(const MediaPause& _Other) = delete;
	MediaPause& operator=(MediaPause&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPauses;

};

