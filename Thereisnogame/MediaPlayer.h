#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MediaPlayer : public G_ActorBase
{
public:
	// constrcuter destructer
	MediaPlayer();
	~MediaPlayer();

	// delete Function
	MediaPlayer(const MediaPlayer& _Other) = delete;
	MediaPlayer(MediaPlayer&& _Other) noexcept = delete;
	MediaPlayer& operator=(const MediaPlayer& _Other) = delete;
	MediaPlayer& operator=(MediaPlayer&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPlayers;

};

