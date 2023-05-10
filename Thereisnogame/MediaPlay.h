#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MediaPlay : public G_ActorBase
{
public:
	// constrcuter destructer
	MediaPlay();
	~MediaPlay();

	// delete Function
	MediaPlay(const MediaPlay& _Other) = delete;
	MediaPlay(MediaPlay&& _Other) noexcept = delete;
	MediaPlay& operator=(const MediaPlay& _Other) = delete;
	MediaPlay& operator=(MediaPlay&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPlays;

};

